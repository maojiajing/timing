#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TCut.h"
#include "TGraph.h"
#include "TLegend.h"
#include <sstream>
#include <string>

void isoplotsnopu() {
  
//   gStyle->SetOptStat(0111100);
  gStyle->SetOptStat(0);
  
  TFile *fin = TFile::Open("muontimingtt50.root");
  TTree *tree = (TTree*)fin->Get("muonIsoTiming/TimingTree"); 
  
  TFile *finprompt = TFile::Open("muontimingzmm50.root");
  TTree *treeprompt = (TTree*)finprompt->Get("muonIsoTiming/TimingTree"); 
  
  
  TFile *finnopu = TFile::Open("muontimingttnopu.root");
  TTree *treenopu = (TTree*)finnopu->Get("muonIsoTiming/TimingTree"); 
  
  TFile *finpromptnopu = TFile::Open("muontimingzmmnopu.root");
  TTree *treepromptnopu = (TTree*)finpromptnopu->Get("muonIsoTiming/TimingTree");   
  
  TCut promptsel = "genMatched && pt>15.";
  TCut fakesel = "!genMatched && pt>15.";
  
  TH1D *hptprompt = new TH1D("hptprompt","",17,15.,100.);
  TH1D *hptfake = new TH1D("hptfake","",17,15.,100.);
  
  treeprompt->Draw("pt>>hptprompt","genMatched","goff");
  tree->Draw("pt>>hptfake","!genMatched","goff");
  
  hptprompt->SetLineColor(kBlue);
  hptfake->SetLineColor(kRed);
  
  hptprompt->Scale(1./hptprompt->GetSumOfWeights());
  hptfake->Scale(1./hptfake->GetSumOfWeights());
  
  TCanvas *cpt = new TCanvas;
  hptfake->Draw("HIST");
  hptprompt->Draw("HISTSAME");
  
  TLegend *leg = new TLegend(0.6,0.6,0.85,0.85);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->AddEntry(hptprompt,"Prompt PU50","L");
  leg->AddEntry(hptfake,"Fake PU50","L");
  leg->Draw();
  
  TH1D *hisoprompt = new TH1D("hisoprompt","",20,0.,20.);
  TH1D *hisocutprompt[7];
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo1_str = "hisocutprompt"+Convert.str();
    hisocutprompt[i-1] = new TH1D(histo1_str.c_str(),"",20,0.,20.);
  }
  
  treeprompt->Draw("min(ecalPFIsoAll,19.9)>>hisoprompt",promptsel,"goff");
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo1_str = "hisocutprompt"+Convert.str();
    std::string cut_str = "ecalPFIsoTCut"+Convert.str();
    std::string draw1_str = "min("+cut_str+",19.9)>>"+histo1_str;
    treeprompt->Draw(draw1_str.c_str(),promptsel,"goff");
  }
    
  hisoprompt->SetLineColor(kMagenta);
  for(int i=1;i<=7;i++){
    hisocutprompt[i-1]->SetLineColor(0+i);
  }
  
//   hptprompt->Scale(1./hptprompt->GetSumOfWeights());
//   hptfake->Scale(1./hptfake->GetSumOfWeights());
  
  TCanvas *cisoprompt = new TCanvas;
  hisocutprompt[0]->Draw("HIST");
  for(int i=2;i<=7;i++){
    hisocutprompt[i-1]->Draw("HISTSAME");
  }
  hisoprompt->Draw("HISTSAME");
  cisoprompt->SetLogy();
  
  TLegend *legisoprompt = new TLegend(0.6,0.6,0.85,0.85);
  legisoprompt->SetBorderSize(0);
  legisoprompt->SetFillStyle(0);
  legisoprompt->AddEntry(hisoprompt,"PU50","L");
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string leg1_str = "PU50+Timing Cut"+Convert.str();
    legisoprompt->AddEntry(hisocutprompt[i-1],leg1_str.c_str(),"L");
  }
  legisoprompt->Draw();  
  
  
  TH1D *hisofake = new TH1D("hisofake","",20,0.,20.);
  TH1D *hisocutfake[7];
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo2_str = "hisocutfake"+Convert.str();
    hisocutfake[i-1] = new TH1D(histo2_str.c_str(),"",20,0.,20.);
  }
  
  tree->Draw("min(ecalPFIsoAll,19.9)>>hisofake",fakesel,"goff");
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo2_str = "hisocutfake"+Convert.str();
    std::string cut_str = "ecalPFIsoTCut"+Convert.str();
    std::string draw2_str = "min("+cut_str+",19.9)>>"+histo2_str;
    tree->Draw(draw2_str.c_str(),fakesel,"goff");
  }
  
  hisofake->SetLineColor(kMagenta);
  for(int i=1;i<=7;i++){
    hisocutfake[i-1]->SetLineColor(0+i);
  }
  
//   hptfake->Scale(1./hptfake->GetSumOfWeights());
//   hptfake->Scale(1./hptfake->GetSumOfWeights());
  
  TCanvas *cisofake = new TCanvas;
  hisocutfake[0]->Draw("HIST");
  for(int i=2;i<=7;i++){
    hisocutfake[i-1]->Draw("HISTSAME");
  }
  hisofake->Draw("HISTSAME");
  cisofake->SetLogy();
  
  TLegend *legisofake = new TLegend(0.6,0.6,0.85,0.85);
  legisofake->SetBorderSize(0);
  legisofake->SetFillStyle(0);
  legisofake->AddEntry(hisofake,"PU50","L");
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string leg2_str = "PU50+Timing Cut"+Convert.str();
    legisofake->AddEntry(hisocutfake[i-1],leg2_str.c_str(),"L");
  }
  legisofake->Draw();  
  
  
  
  TH1D *hisopromptfine = new TH1D("hisopromptfine","",5000,0.,20.);
  TH1D *hisopromptnopufine = new TH1D("hisopromptnopufine","",5000,0.,20.);
  TH1D *hisocutpromptnopufine[7];
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo3_str = "hisocutpromptnopufine"+Convert.str();
    hisocutpromptnopufine[i-1] = new TH1D(histo3_str.c_str(),"",5000,0.,20.);
  }
  
  treeprompt->Draw("ecalPFIsoAll>>hisopromptfine",promptsel,"goff");
  treepromptnopu->Draw("ecalPFIsoAll>>hisopromptnopufine",promptsel,"goff");
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo3_str = "hisocutpromptnopufine"+Convert.str();
    std::string cut_str = "ecalPFIsoTCut"+Convert.str();
    std::string draw3_str = cut_str+">>"+histo3_str;
    treepromptnopu->Draw(draw3_str.c_str(),promptsel,"goff");
  }
  
  
  TH1D *hisofakenopufine = new TH1D("hisofakenopufine","",5000,0.,20.);
  TH1D *hisocutfakenopufine[7];
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo4_str = "hisocutfakenopufine"+Convert.str();
    hisocutfakenopufine[i-1] = new TH1D(histo4_str.c_str(),"",5000,0.,20.);
  }
  
  tree->Draw("ecalPFIsoAll>>hisofakenopufine",fakesel,"goff");
  for(int i=1;i<=7;i++){
    ostringstream Convert;
    Convert<<i;
    std::string histo4_str = "hisocutfakenopufine"+Convert.str();
    std::string cut_str = "ecalPFIsoTCut"+Convert.str();
    std::string draw4_str = cut_str+">>"+histo4_str;
    tree->Draw(draw4_str.c_str(),fakesel,"goff");
  }
  
  
  int nbins = hisopromptfine->GetNbinsX();
  
  TGraph *hrocall = new TGraph(nbins);
  TGraph* hroccut[7];
  for(int i=1;i<=7;i++){
    hroccut[i-1] = new TGraph(nbins);
  }
  
  double prompttotal = hisopromptfine->Integral(0,nbins+1);
  double promptnoputotal = hisopromptnopufine->Integral(0.,nbins+1);
  double fakenoputotal = hisofakenopufine->Integral(0,nbins+1);
  
//   double promptcut = hisopromptfine->Integral(0,nbins+1);
  
  for (int ibin=0; ibin<nbins; ++ibin) {
    double promptnopuall = hisopromptnopufine->Integral(0,ibin);
    double fakenopuall = hisofakenopufine->Integral(0,ibin);
    double promptnopucut[7];
    double fakenopucut[7];
    for(int i=1;i<=7;i++){
      promptnopucut[i-1] = hisocutpromptnopufine[i-1]->Integral(0,ibin);
      fakenopucut[i-1] = hisocutfakenopufine[i-1]->Integral(0,ibin);
     }
    
    double effpromptnopuall = promptnopuall/promptnoputotal;
    double efffakenopuall = fakenopuall/fakenoputotal;
    double effpromptnopucut[7];
    double efffakenopucut[7];
    for(int i=1;i<=7;i++){
      effpromptnopucut[i-1] = promptnopucut[i-1]/promptnoputotal;
      efffakenopucut[i-1] = fakenopucut[i-1]/fakenoputotal;
     }
    
    hrocall->SetPoint(ibin,efffakenopuall,effpromptnopuall);
    //hroccut->SetPoint(ibin,efffakecut,effpromptnopucut);
    for(int i=1;i<=7;i++){
      hroccut[i-1]->SetPoint(ibin,efffakenopucut[i-1],effpromptnopucut[i-1]);
    }
    
  }
  
  hrocall->SetLineColor(kRed);
  hrocall->SetLineStyle(9);
  hrocall->SetLineWidth(2);
  for(int i=1;i<=7;i++){
    hroccut[i-1]->SetLineColor(0+i);
  }
  
  TCanvas *cisoroc = new TCanvas;
  hrocall->Draw("AL");
  for(int i=1;i<=7;i++){
    hroccut[i-1]->Draw("LSAME");
  }
  
  TLegend *legisoroc = new TLegend(0.65,0.5,0.85,0.75);
  legisoroc->SetBorderSize(0);
  legisoroc->SetFillStyle(0);
  legisoroc->AddEntry(hrocall,"ROC NoPU ALL","L");
  legisoroc->AddEntry(hroccut[0],"ROC NoPU Cut @ 100ps","L");
  for(int i=2;i<=7;i++){
    ostringstream Convert;
    int j=i*100;
    Convert<<j;
    std::string leg5_str = "ROC NoPU Cut @ "+Convert.str()+"ps";
    legisoroc->AddEntry(hroccut[i-1],leg5_str.c_str(),"L");
  }
  legisoroc->Draw();  
  
  TH1D *hdtprompt = new TH1D("hdtprompt","",50,-1.,1.);
  TH1D *hdtpromptnopu = new TH1D("hdtpromptnopu","",50,-1.,1.);
  
  treeprompt->Draw("clusTsmeared-vtxT>>hdtprompt",promptsel,"goff");
  treepromptnopu->Draw("clusTsmeared-vtxT>>hdtpromptnopu",promptsel,"goff"); 
  
  hdtprompt->SetLineColor(kMagenta);
  hdtpromptnopu->SetLineColor(kBlue);
  
  hdtprompt->Scale(1./prompttotal);
  hdtpromptnopu->Scale(1./promptnoputotal);
  
  
  hdtprompt->GetXaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
  hdtprompt->GetYaxis()->SetTitle("# of clusters/bin/muon");
  
  TCanvas *cdtprompt = new TCanvas;
  hdtprompt->Draw("HIST");
  hdtpromptnopu->Draw("HISTSAME");
  
  TLegend *legpu = new TLegend(0.6,0.6,0.85,0.85);
  legpu->SetBorderSize(0);
  legpu->SetFillStyle(0);
  legpu->AddEntry(hdtpromptnopu,"NoPU","L");
  legpu->AddEntry(hdtprompt,"PU50","L");
  legpu->Draw();    
  
  cdtprompt->SaveAs("dtpromptsmeared.pdf");
  
  
//   TCut sel = "Entry$<100";
  
//   events->Draw("floatss_ecalBarrelClusterFastTimer_PerfectResolutionModel_RECO.obj[0][] - recoVertexs_offlinePrimaryVertices4D__RECO.obj[0].time_>>htimenopu",sel,"goff");
//   eventspu->Draw("floatss_ecalBarrelClusterFastTimer_PerfectResolutionModel_RECO.obj[0][] - recoVertexs_offlinePrimaryVertices4D__RECO.obj[0].time_>>htimepu",sel,"goff");

  
//   eventspu->Draw("floatss_ecalBarrelClusterFastTimer_PerfectResolutionModel_RECO.obj[0][]>>htimepu",sel,"goff");
  
//   htimepu->SetLineColor(kRed);
//   htimepu->SetMarkerColor(kRed);
//   
//   htimepu->GetXaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
//   htimepu->GetYaxis()->SetTitle("# of clusters");
//   
//   TCanvas *c = new TCanvas;
//   htimepu->Draw("HIST");
//   htimepu->SetMinimum(0.);
//   htimenopu->Draw("HISTSAME");
//   
//   TLegend *leg = new TLegend(0.6,0.6,0.85,0.85);
//   leg->AddEntry(htimenopu,"NoPU","L");
//   leg->AddEntry(htimepu,"PU50","L");
//   leg->Draw();
//   
//   c->SaveAs("timing.pdf");
}
