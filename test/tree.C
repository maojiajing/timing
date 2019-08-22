#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TCut.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TRandom.h"
#include <sstream>
#include <string>
#include "TMath.h"
#include "stdlib.h"

void tree() {
  
//   gStyle->SetOptStat(0111100);
  gStyle->SetOptStat(0);
  
  TFile *fin = TFile::Open("muontimingzmm200.root");
  TTree *tree = (TTree*)fin->Get("muonIsoTiming/TimingTree"); 
  
  TCut promptsel = "genMatched && pt>15.";
  TCut fakesel = "!genMatched && pt>15.";
  
//*****************************************************
//TGraph to see correlation
//***************************************************** 
  
  float eta;
  float vtxT;
  std::vector<float> *clusE;
  std::vector<float> *clusEta;
  std::vector<float> *clusT;
  std::vector<float> *deltaEta;
  std::vector<float> *deltaPhi;
  std::vector<float> *deltaT;

  tree->SetBranchAddress("eta",&eta); 
  tree->SetBranchAddress("vtxT",&vtxT); 
  tree->SetBranchAddress("clusE",(&clusE));
  tree->SetBranchAddress("clusEta",(&clusEta));
  tree->SetBranchAddress("clusT",(&clusT));
  tree->SetBranchAddress("deltaEta",(&deltaEta));
  tree->SetBranchAddress("deltaPhi",(&deltaPhi));
  tree->SetBranchAddress("deltaT",(&deltaT));

  int entries = tree->GetEntries();

  int bins = 0;

  for(int ientry=0;ientry<entries;ientry++){
    cout << "ientry = " << ientry << "\n";
    tree->GetEntry(ientry);
    int nclus = 0;
    nclus = clusT->size();
    bins+=nclus;
    cout << "size = " << nclus << "\n";
    for(int iclus=0;iclus<nclus;iclus++){
        cout << "iclus = " << iclus << "\n";
        cout << " deltaT->at(iclus) = " << deltaT->at(iclus) <<"\n";
        cout << " VtxT = " << vtxT <<"\n";
        cout << " clusT = " << clusT->at(iclus) <<"\n";
        cout << " dt = " << clusT->at(iclus)-vtxT <<"\n";
        //hdteta->SetPoint(ientry,eta,deltaT->at(iclus));
    }
  }
 
  TGraph *hdteta = new TGraph(bins);
  TGraph *hdtcluse = new TGraph(bins);
  TGraph *hdtcluseta = new TGraph(bins);
  TGraph *hdtdeltaeta = new TGraph(bins);
  TGraph *hdtdeltaphi = new TGraph(bins);
 
  int ibin = 0;

  //cout << "ibin, eta, deltaT->at(iclus)  " <<"\n";
  
  for(int ientry=0;ientry<entries;ientry++){
    //cout << "ientry = " << ientry << "\n";
    tree->GetEntry(ientry);
    int nclus = 0;
    nclus = clusT->size();
    //cout << "size = " << nclus << "\n";
    for(int iclus=0;iclus<nclus;iclus++){
      //cout << "iclus = " << iclus << "\n";
      //cout << "ibin = " << ibin << "\n";
      //cout << "eta = " << eta << "\n";
      //cout << " deltaT->at(iclus) = " << deltaT->at(iclus) <<"\n";
      //cout << ibin <<" "<< eta <<" "<< deltaT->at(iclus) <<"\n";
      hdteta->SetPoint(ibin,eta,deltaT->at(iclus));
      hdtcluse->SetPoint(ibin,clusE->at(iclus),deltaT->at(iclus));
      hdtcluseta->SetPoint(ibin,clusEta->at(iclus),deltaT->at(iclus));
      hdtdeltaeta->SetPoint(ibin,deltaEta->at(iclus),deltaT->at(iclus));
      hdtdeltaphi->SetPoint(ibin,deltaPhi->at(iclus),deltaT->at(iclus));
      ibin++;
    }
  }
  //hdteta->SetLineColor(kMagenta);

  TCanvas *cdteta = new TCanvas;
  hdteta->Draw("A*");
  hdteta->SetMarkerColor(kMagenta);
  hdteta->SetMarkerStyle(33);
  hdteta->SetMarkerSize(0.5);

  hdteta->GetXaxis()->SetTitle("Eta_muon");
  hdteta->GetYaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
 
  TLegend *legdteta = new TLegend(0.65,0.5,0.85,0.75);
  legdteta->SetBorderSize(0);
  legdteta->SetFillStyle(0);
  legdteta->AddEntry(hdteta,"pu50","P");
  legdteta->Draw();
   
  TCanvas *cdtcluse = new TCanvas;
  hdtcluse->Draw("A*");
  hdtcluse->SetMarkerColor(kMagenta);
  hdtcluse->SetMarkerStyle(33);
  hdtcluse->SetMarkerSize(0.5);

  hdtcluse->GetXaxis()->SetTitle("E_cluster");
  hdtcluse->GetYaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
 
  TLegend *legdtcluse = new TLegend(0.65,0.5,0.85,0.75);
  legdtcluse->SetBorderSize(0);
  legdtcluse->SetFillStyle(0);
  legdtcluse->AddEntry(hdtcluse,"pu50","P");
  legdtcluse->Draw();
   
  TCanvas *cdtcluseta = new TCanvas;
  hdtcluseta->Draw("A*");
  hdtcluseta->SetMarkerColor(kMagenta);
  hdtcluseta->SetMarkerStyle(33);
  hdtcluseta->SetMarkerSize(0.5);

  hdtcluseta->GetXaxis()->SetTitle("Eta_cluster");
  hdtcluseta->GetYaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
 
  TLegend *legdtcluseta = new TLegend(0.65,0.5,0.85,0.75);
  legdtcluseta->SetBorderSize(0);
  legdtcluseta->SetFillStyle(0);
  legdtcluseta->AddEntry(hdtcluseta,"pu50","P");
  legdtcluseta->Draw();
   
  TCanvas *cdtdeltaeta = new TCanvas;
  hdtdeltaeta->Draw("A*");
  hdtdeltaeta->SetMarkerColor(kMagenta);
  hdtdeltaeta->SetMarkerStyle(33);
  hdtdeltaeta->SetMarkerSize(0.5);

  hdtdeltaeta->GetXaxis()->SetTitle("deltaEta(cluster,muon)");
  hdtdeltaeta->GetYaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
 
  TLegend *legdtdeltaeta = new TLegend(0.65,0.5,0.85,0.75);
  legdtdeltaeta->SetBorderSize(0);
  legdtdeltaeta->SetFillStyle(0);
  legdtdeltaeta->AddEntry(hdtdeltaeta,"pu50","P");
  legdtdeltaeta->Draw();
  
  TCanvas *cdtdeltaphi = new TCanvas;
  hdtdeltaphi->Draw("A*");
  hdtdeltaphi->SetMarkerColor(kMagenta);
  hdtdeltaphi->SetMarkerStyle(33);
  hdtdeltaphi->SetMarkerSize(0.5);

  hdtdeltaphi->GetXaxis()->SetTitle("deltaPhi(cluster,muon)");
  hdtdeltaphi->GetYaxis()->SetTitle("#Delta t(cluster,vtx0) (ns)");
 
  TLegend *legdtdeltaphi = new TLegend(0.65,0.5,0.85,0.75);
  legdtdeltaphi->SetBorderSize(0);
  legdtdeltaphi->SetFillStyle(0);
  legdtdeltaphi->AddEntry(hdtdeltaphi,"pu50","P");
  legdtdeltaphi->Draw();
}
