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

void testpu200() {
  
//   gStyle->SetOptStat(0111100);
  gStyle->SetOptStat(0);
  
  TFile *fin = TFile::Open("muontimingtt200.root");
  TTree *tree = (TTree*)fin->Get("muonIsoTiming/TimingTree"); 
  
  TFile *finprompt = TFile::Open("muontimingzmm200.root");
  TTree *treeprompt = (TTree*)finprompt->Get("muonIsoTiming/TimingTree"); 
  
  TFile *fin50 = TFile::Open("muontimingtt50.root");
  TTree *tree50 = (TTree*)fin->Get("muonIsoTiming/TimingTree"); 
  
  TFile *finprompt50 = TFile::Open("muontimingzmm50.root");
  TTree *treeprompt50 = (TTree*)finprompt->Get("muonIsoTiming/TimingTree"); 
  
  
  TFile *finnopu = TFile::Open("muontimingttnopu.root");
  TTree *treenopu = (TTree*)finnopu->Get("muonIsoTiming/TimingTree"); 
  
  TFile *finpromptnopu = TFile::Open("muontimingzmmnopu.root");
  TTree *treepromptnopu = (TTree*)finpromptnopu->Get("muonIsoTiming/TimingTree");   
  
  TCut promptsel = "genMatched && pt>15.";
  TCut fakesel = "!genMatched && pt>15.";
  
  TH1D *hisopromptfine = new TH1D("hisopromptfine","",5000,0.,20.);
  TH1D *hisopromptnopufine = new TH1D("hisopromptnopufine","",5000,0.,20.);
  
  treeprompt->Draw("ecalPFIsoAll>>hisopromptfine",promptsel,"goff");
  treepromptnopu->Draw("ecalPFIsoAll>>hisopromptnopufine",promptsel,"goff");
  
  
  TH1D *hisofakefine = new TH1D("hisofakefine","",5000,0.,20.);
  TH1D *hisofakenopufine = new TH1D("hisofakenopufine","",5000,0.,20.);
  
  tree->Draw("ecalPFIsoAll>>hisofakefine",fakesel,"goff");
  treenopu->Draw("ecalPFIsoAll>>hisofakenopufine",fakesel,"goff");
  
  
  TH1D *hisoprompt50fine = new TH1D("hisoprompt50fine","",5000,0.,20.);
  TH1D *hisoprompt50nopufine = new TH1D("hisoprompt50nopufine","",5000,0.,20.);
  
  treeprompt50->Draw("ecalPFIsoAll>>hisoprompt50fine",promptsel,"goff");
  treepromptnopu->Draw("ecalPFIsoAll>>hisoprompt50nopufine",promptsel,"goff");
  
  
  TH1D *hisofake50fine = new TH1D("hisofake50fine","",5000,0.,20.);
  TH1D *hisofake50nopufine = new TH1D("hisofake50nopufine","",5000,0.,20.);
  
  tree50->Draw("ecalPFIsoAll>>hisofake50fine",fakesel,"goff");
  treenopu->Draw("ecalPFIsoAll>>hisofake50nopufine",fakesel,"goff");
 
  int nbins = hisopromptfine->GetNbinsX(); 
  
  double prompttotal = hisopromptfine->Integral(0,nbins+1);
  double prompt50total = hisoprompt50fine->Integral(0,nbins+1);
  double promptnoputotal = hisopromptnopufine->Integral(0.,nbins+1);

  double faketotal = hisofakefine->Integral(0,nbins+1);
  double fake50total = hisofake50fine->Integral(0,nbins+1);
  double fakenoputotal = hisofakenopufine->Integral(0,nbins+1);
  
  
  TH1D *hdtprompt = new TH1D("hdtprompt","",50,-1.,1.);
  TH1D *hdtprompt50 = new TH1D("hdtprompt50","",50,-1.,1.);
  TH1D *hdtpromptnopu = new TH1D("hdtpromptnopu","",50,-1.,1.);

  TH1D *hdtfake = new TH1D("hdtfake","",50,-1.,1.);
  TH1D *hdtfake50 = new TH1D("hdtfake50","",50,-1.,1.);
  TH1D *hdtfakenopu = new TH1D("hdtfakenopu","",50,-1.,1.);

  treeprompt->Draw("clusTsmeared-vtxT>>hdtprompt",promptsel,"goff");
  treeprompt50->Draw("clusTsmeared-vtxT>>hdtprompt50",promptsel,"goff");
  treepromptnopu->Draw("clusTsmeared-vtxT>>hdtpromptnopu",promptsel,"goff");

  tree->Draw("clusTsmeared-vtxT>>hdtfake",fakesel,"goff");
  tree50->Draw("clusTsmeared-vtxT>>hdtfake50",fakesel,"goff");
  treenopu->Draw("clusTsmeared-vtxT>>hdtfakenopu",fakesel,"goff");

  hdtprompt->SetLineColor(kGreen);
  hdtprompt->SetLineWidth(1);
  hdtprompt->SetLineStyle(8);
  hdtprompt50->SetLineColor(kRed);
  hdtprompt50->SetLineStyle(9);
  hdtpromptnopu->SetLineColor(kBlue);

  hdtfake->SetLineColor(kGreen);
  hdtfake->SetLineWidth(1);
  hdtfake->SetLineStyle(8);
  hdtfake50->SetLineColor(kRed);
  hdtfake50->SetLineStyle(9);
  hdtfakenopu->SetLineColor(kBlue);

  hdtprompt->Scale(1./prompttotal);
  hdtprompt50->Scale(1./prompt50total);
  hdtpromptnopu->Scale(1./promptnoputotal);

  hdtfake->Scale(1./faketotal);
  hdtfake50->Scale(1./fake50total);
  hdtfakenopu->Scale(1./fakenoputotal);


  hdtprompt->GetXaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
  hdtprompt->GetYaxis()->SetTitle("# of clusters/bin/muon");

  TCanvas *cdtprompt = new TCanvas;
  hdtprompt->Draw("HIST");
  hdtprompt50->Draw("HISTSAME");
  hdtpromptnopu->Draw("HISTSAME");

  TLegend *legprompt = new TLegend(0.6,0.6,0.85,0.85);
  legprompt->SetBorderSize(0);
  legprompt->SetFillStyle(0);
  legprompt->AddEntry(hdtpromptnopu,"NoPUprompt","L");
  legprompt->AddEntry(hdtprompt,"~PU200prompt","L");
  legprompt->AddEntry(hdtprompt50,"PU50prompt","L");
  legprompt->Draw();    
 
  cdtprompt->SaveAs("dtpromptsmeared.pdf");

  hdtfake->GetXaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
  hdtfake->GetYaxis()->SetTitle("# of clusters/bin/muon");

  TCanvas *cdtfake = new TCanvas;
  hdtfake->Draw("HIST");
  hdtfake50->Draw("HISTSAME");
  hdtfakenopu->Draw("HISTSAME");

  TLegend *legfake = new TLegend(0.6,0.6,0.85,0.85);
  legfake->SetBorderSize(0);
  legfake->SetFillStyle(0);
  legfake->AddEntry(hdtfakenopu,"NoPUfake","L");
  legfake->AddEntry(hdtfake,"~PU200fake","L");
  legfake->AddEntry(hdtfake50,"PU50fake","L");
  legfake->Draw();    
 
  cdtfake->SaveAs("dtfakesmeared.pdf");
  
}
