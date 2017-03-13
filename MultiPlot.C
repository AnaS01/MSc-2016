#include "TH1.h"
#include "TF1.h"
#include "TH3.h"
#include "TList.h"
#include "math.h"
#include "TStyle.h"
#include "TMinuit.h"

void MultiPlot() {

  TFile *PbPbMC = new TFile("zJetsPbPbMCFinal.root");
  TFile *PbPbData = new TFile("zJetsPbPbFinal.root");
  TFile *PPMC = new TFile("zJetsPPMCFinal.root");
  TFile *PPData = new TFile("zJetsPPFinal.root");

  /*--------------mass fitting --------------*/
  TCanvas *c1 = new TCanvas;

  TH1F *motherMassPbPbMC = (TH1F*)PbPbMC->Get("demo/motherInvMass");
  motherMassPbPbMC->SetTitle("Invariant mass of the Z boson candidates for PbPb MC simulations");
  motherMassPbPbMC->SetXTitle("Invariant mass of muon-antimuon pair, (GeV)");
  motherMassPbPbMC->SetYTitle("Number of particles");
  gStyle->SetOptFit(1111); 
  c1->Update();

  TH1F *massPbPbMC1 = (TH1F*)motherMassPbPbMC->Clone("Fitted with Gaussian distribution over the entire range");;
  TF1 *g1    = new TF1("g1","gaus");
  g1->SetLineColor(kBlack);   
  massPbPbMC1->Fit(g1, "M,E,I");
  c1->Update();
  TPaveStats *statsPbPbMC1 = (TPaveStats*)massPbPbMC1->FindObject("stats");
  statsPbPbMC1->SetX1NDC(0.9);
  statsPbPbMC1->SetX2NDC(0.7);
  statsPbPbMC1->SetY1NDC(0.9);
  statsPbPbMC1->SetY2NDC(0.65);
  statsPbPbMC1->SetTextColor(kBlack);
  c1->Update();

  TH1F *massPbPbMC2 = (TH1F*)motherMassPbPbMC->Clone("Fitted with Gaussian distribution over the range of 82-99GeV");
  TF1 *g2    = new TF1("g2","gaus",82,99);
  g2->SetLineColor(kRed); 
  massPbPbMC2->Fit(g2,"R+,M, E,I", "sames");
  c1->Update();

  TPaveStats *statsPbPbMC2 = (TPaveStats*)massPbPbMC2->FindObject("stats");
  statsPbPbMC2->SetX1NDC(0.9);
  statsPbPbMC2->SetX2NDC(0.7);
  statsPbPbMC2->SetY1NDC(0.65);
  statsPbPbMC2->SetY2NDC(0.4);
  statsPbPbMC2->SetTextColor(kRed);
  c1->Update();

  TH1F *massPbPbMC3 = (TH1F*)motherMassPbPbMC->Clone("Fitted with Gaussian distribution over the range of 85-97GeV");
  TF1 *g3    = new TF1("g3","gaus",85,97);
  g3->SetLineColor(kBlue); 
  massPbPbMC3->Fit(g3,"R+,M, E, I", "sames");
  c1->Update();
  TPaveStats *statsPbPbMC3 = (TPaveStats*)massPbPbMC3->FindObject("stats");
  statsPbPbMC3->SetX1NDC(0.9);
  statsPbPbMC3->SetX2NDC(0.7);
  statsPbPbMC3->SetY1NDC(0.4);
  statsPbPbMC3->SetY2NDC(0.15);
  statsPbPbMC3->SetTextColor(kBlue);
  c1->Modified();

  c1->SaveAs("MassPbPbMC.eps");

  TCanvas*c2 = new TCanvas;

  TH1F *motherMassPbPbData = (TH1F*)PbPbData->Get("demo/motherInvMass");
  motherMassPbPbData->SetTitle("Invariant mass of the Z boson candidates PbPb data collisions");
  motherMassPbPbData->SetXTitle("Invariant mass of muon-antimuon pair, (GeV)");
  motherMassPbPbData->SetYTitle("Number of particles");
  gStyle->SetOptFit(1111);
  c2->Update();

  TH1F *massPbPbData1 = (TH1F*)motherMassPbPbData->Clone("Fitted with Gaussian distribution over the entire range"); 
  massPbPbData1->Fit(g1,"M,E,I");
  c2->Update();

  TPaveStats *statsPbPbData1 = (TPaveStats*)massPbPbData1->FindObject("stats");
  statsPbPbData1->SetX1NDC(0.9);
  statsPbPbData1->SetX2NDC(0.7);
  statsPbPbData1->SetY1NDC(0.9);
  statsPbPbData1->SetY2NDC(0.65);
  statsPbPbData1->SetTextColor(kBlack);
  c2->Update();

  TH1F *massPbPbData2 = (TH1F*)motherMassPbPbData->Clone("Fitted with Gaussian distribution over the range of 82-99GeV");
  massPbPbData2->Fit(g2,"R+,M,E,I", "sames");
  c2->Update();

  TPaveStats *statsPbPbData2 = (TPaveStats*)massPbPbData2->FindObject("stats");
  statsPbPbData2->SetX1NDC(0.9);
  statsPbPbData2->SetX2NDC(0.7);
  statsPbPbData2->SetY1NDC(0.65);
  statsPbPbData2->SetY2NDC(0.4);
  statsPbPbData2->SetTextColor(kRed);
  c2->Update();

  TH1F *massPbPbData3 = (TH1F*)motherMassPbPbData->Clone("Fitted with Gaussian distribution over the range of 85-97GeV");
  massPbPbData3->Fit(g3,"R+,M,E,I", "sames");
  c2->Update();

  TPaveStats *statsPbPbData3 = (TPaveStats*)massPbPbData3->FindObject("stats");
  statsPbPbData3->SetX1NDC(0.9);
  statsPbPbData3->SetX2NDC(0.7);
  statsPbPbData3->SetY1NDC(0.4);
  statsPbPbData3->SetY2NDC(0.15);
  statsPbPbData3->SetTextColor(kBlue);
  c2->Modified();

  c2->SaveAs("MassPbPbData.eps");
 
  TCanvas *c3 = new TCanvas;

  TH1F *motherMassPPMC = (TH1F*)PPMC->Get("demo/motherInvMass");
  motherMassPPMC->SetTitle("Invariant mass of the Z boson candidates in proton-proton MC simulations");
  motherMassPPMC->SetXTitle("Invariant mass of muon-antimuon pair, (GeV)");
  motherMassPPMC->SetYTitle("Number of particles");
  gStyle->SetOptFit(1111);
  c3->Update();

  TH1F *massPPMC1 = (TH1F*)motherMassPPMC->Clone("Fitted with Gaussian distribution over the entire range"); 
  massPPMC1->Fit(g1, "M,E,I");
  c3->Update();

  TPaveStats *statsPPMC1 = (TPaveStats*)massPPMC1->FindObject("stats");
  statsPPMC1->SetX1NDC(0.9);
  statsPPMC1->SetX2NDC(0.7);
  statsPPMC1->SetY1NDC(0.9);
  statsPPMC1->SetY2NDC(0.65);
  statsPPMC1->SetTextColor(kBlack);
  c3->Update();

  TH1F *massPPMC2 = (TH1F*)motherMassPPMC->Clone("Fitted with Gaussian distribution over the range of 82-99GeV");
  massPPMC2->Fit(g2,"R+,M,E,I", "sames");
  c3->Update();

  TPaveStats *statsPPMC2 = (TPaveStats*)massPPMC2->FindObject("stats");
  statsPPMC2->SetX1NDC(0.9);
  statsPPMC2->SetX2NDC(0.7);
  statsPPMC2->SetY1NDC(0.65);
  statsPPMC2->SetY2NDC(0.4);
  statsPPMC2->SetTextColor(kRed);
  c3->Update();

  TH1F *massPPMC3 = (TH1F*)motherMassPPMC->Clone("Fitted with Gaussian distribution over the range of 85-97GeV");
  massPPMC3->Fit(g3,"R+,M,E,I", "sames");
  c3->Update();

  TPaveStats *statsPPMC3 = (TPaveStats*)massPPMC3->FindObject("stats");
  statsPPMC3->SetX1NDC(0.9);
  statsPPMC3->SetX2NDC(0.7);
  statsPPMC3->SetY1NDC(0.4);
  statsPPMC3->SetY2NDC(0.15);
  statsPPMC3->SetTextColor(kBlue);
  c3->Modified();

  c3->SaveAs("MassPPMC.eps");

  TCanvas *c4 = new TCanvas;

  TH1F *motherMassPPData = (TH1F*)PPData->Get("demo/motherInvMass");
  motherMassPPData->SetTitle("Invariant mass of the Z boson candidates in proton-proton collisions");
  motherMassPPData->SetXTitle("Invariant mass the of muon-antimuon pair, (GeV)");
  motherMassPPData->SetYTitle("Number of particles");
  gStyle->SetOptFit(1111);
  c4->Update();

  TH1F *massPPData1 = (TH1F*)motherMassPPData->Clone("Fitted with Gaussian distribution over the entire range"); 
  massPPData1->Fit(g1, "M,E,I");
  c4->Update();

  TPaveStats *statsPPData1 = (TPaveStats*)massPPData1->FindObject("stats");
  statsPPData1->SetX1NDC(0.9);
  statsPPData1->SetX2NDC(0.7);
  statsPPData1->SetY1NDC(0.9);
  statsPPData1->SetY2NDC(0.65);
  statsPPData1->SetTextColor(kBlack);
  c4->Update();

  TH1F *massPPData2 = (TH1F*)motherMassPPData->Clone("Fitted with Gaussian distribution over the range of 82-99GeV");
  massPPData2->Fit(g2,"R+,M,E,I", "sames");
  c4->Update();

  TPaveStats *statsPPData2 = (TPaveStats*)massPPData2->FindObject("stats");
  statsPPData2->SetX1NDC(0.9);
  statsPPData2->SetX2NDC(0.7);
  statsPPData2->SetY1NDC(0.65);
  statsPPData2->SetY2NDC(0.4);
  statsPPData2->SetTextColor(kRed);
  c4->Update();

  TH1F *massPPData3 = (TH1F*)motherMassPPData->Clone("Fitted with Gaussian distribution over the range of 85-97GeV");
  massPPData3->Fit(g3,"R+,M,E,I", "sames");
  c4->Update();

  TPaveStats *statsPPData3 = (TPaveStats*)massPPData3->FindObject("stats");
  statsPPData3->SetX1NDC(0.9);
  statsPPData3->SetX2NDC(0.7);
  statsPPData3->SetY1NDC(0.4);
  statsPPData3->SetY2NDC(0.15);
  statsPPData3->SetTextColor(kBlue);
  c4->Update();
  c4->Modified();

  c4->SaveAs("MassPPData.eps");

  /*-----------------------P-----------------------------*/
  TCanvas *pMC = new TCanvas;

  THStack *stackPMC = new THStack("stackPMC", "Momentum, P, of the Z boson candidates in MC simulations");

  TH1F *motherPPbPbMC = (TH1F*)PbPbMC->Get("demo/motherP");
  motherPPbPbMC->SetTitle("Total momentum of the Z boson candidates for heavy ion MC simulations");
  motherPPbPbMC->SetName("Momentum histogram of PbPb MC");
  gStyle->SetOptStat(1111);

  TH1F *motherPPPMC = (TH1F*)PPMC->Get("demo/motherP");
  motherPPPMC->SetTitle("Total momentum of the Z boson candidates for proton-proton MC simulations");
  motherPPPMC->SetName("Momentum histogram of PP MC");
  gStyle->SetOptStat(1111);

  motherPPbPbMC->SetLineColor(kBlack);
  motherPPPMC->SetLineColor(kBlue);

  stackPMC->Add(motherPPbPbMC, "sames");
  stackPMC->Add(motherPPPMC, "sames");

  stackPMC->Draw("ehist nostack");
  pMC->Update();

  TPaveStats *statsPPbPbMC = (TPaveStats*)motherPPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsPPbPbMC->SetX1NDC(0.9); statsPPbPbMC->SetX2NDC(0.7);
  statsPPbPbMC->SetY1NDC(0.9); statsPPbPbMC->SetY2NDC(0.7);
  statsPPbPbMC->SetTextColor(kBlack);

  pMC->Update();

  TPaveStats *statsPPPMC = (TPaveStats*)motherPPPMC->GetListOfFunctions()->FindObject("stats");
  statsPPPMC->SetX1NDC(0.9); statsPPPMC->SetX2NDC(0.7);
  statsPPPMC->SetY1NDC(0.7); statsPPPMC->SetY2NDC(0.5);
  statsPPPMC->SetTextColor(kBlue);

  pMC->Update();

  stackPMC->GetXaxis()->SetTitle("Total momentum of the Z boson candidate, (GeV)");
  stackPMC->GetYaxis()->SetTitle("Number of particles");

  pMC->Update();
  pMC->SaveAs("MomentumMC.eps");
  pMC->Modified();

  TCanvas *pData = new TCanvas;
  THStack *stackPData = new THStack("stackPData", "Momentum, P, of the Z boson candidates in real collisions");

  TH1F *motherPPbPbData = (TH1F*)PbPbData->Get("demo/motherP");
  motherPPbPbData->SetTitle("Total momentum of the Z boson candidates for heavy collisions");
  motherPPbPbData->SetName("Momentum histogram for PbPb data");
  gStyle->SetOptStat(1111);

  TH1F *motherPPPData = (TH1F*)PPData->Get("demo/motherP");
  motherPPPData->SetTitle("Total momentum of the Z boson candidates for proton-proton collisions");
  motherPPPData->SetName("Momentum histogram for PP data");
  gStyle->SetOptStat(1111);

  motherPPbPbData->SetLineColor(kRed);
  motherPPPData->SetLineColor(TColor::GetColorDark(kGreen));
  
  stackPData->Add(motherPPbPbData, "sames");
  stackPData->Add(motherPPPData, "sames");
  stackPData->Draw("ehist nostack");

  pData->Update();

  TPaveStats *statsPPbPbData = (TPaveStats*)motherPPbPbData->GetListOfFunctions()->FindObject("stats");
  statsPPbPbData->SetX1NDC(0.9); statsPPbPbData->SetX2NDC(0.7);
  statsPPbPbData->SetY1NDC(0.9); statsPPbPbData->SetY2NDC(0.7);
  statsPPbPbData->SetTextColor(kRed);

  pData->Update();

  TPaveStats *statsPPPData = (TPaveStats*)motherPPPData->GetListOfFunctions()->FindObject("stats");
  statsPPPData->SetX1NDC(0.9); statsPPPData->SetX2NDC(0.7);
  statsPPPData->SetY1NDC(0.7); statsPPPData->SetY2NDC(0.5);
  statsPPPData->SetTextColor(TColor::GetColorDark(kGreen));

  pData->Update();

  stackPData->GetXaxis()->SetTitle("Total momentum of the Z boson candidate, (GeV)");
  stackPData->GetYaxis()->SetTitle("Number of particles");

  pData->Update();
  pData->SaveAs("MomentumData.eps");
  pData->Modified();

/*-----------------------Pt-----------------------------*/
  TCanvas *ptMC = new TCanvas;
 
  THStack *stackPtMC = new THStack("stackPtMC", "Transverse momentum, Pt, of the Z boson candidates in MC simulations");

  TH1F *motherPtPbPbMC = (TH1F*)PbPbMC->Get("demo/motherPt");
  motherPtPbPbMC->SetTitle("Transverse momentum of the Z boson candidates for heavy ion MC simulations");  
  motherPtPbPbMC->SetName("Transverse momentum for PbPb MC");
  gStyle->SetOptStat(1111);
  ptMC->Update();

  TH1F *motherPtPPMC = (TH1F*)PPMC->Get("demo/motherPt");
  motherPtPPMC->SetTitle("Transverse momentum of the Z boson candidates PP MC simulations");
  motherPtPPMC->SetName("Transverse momentum for PP MC");
  gStyle->SetOptStat(1111);

  motherPtPbPbMC->SetLineColor(kBlack);
  motherPtPPMC->SetLineColor(kBlue);
  
  stackPtMC->Add(motherPtPbPbMC, "sames");
  stackPtMC->Add(motherPtPPMC, "sames");

  stackPtMC->Draw("ehist nostack");

  ptMC->Update();

  TPaveStats *statsPtPbPbMC = (TPaveStats*)motherPtPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsPtPbPbMC->SetX1NDC(0.9); statsPtPbPbMC->SetX2NDC(0.5);
  statsPtPbPbMC->SetY1NDC(0.9); statsPtPbPbMC->SetY2NDC(0.7);
  statsPtPbPbMC->SetTextColor(kBlack);

  ptMC->Update();

  TPaveStats *statsPtPPMC = (TPaveStats*)motherPtPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsPtPPMC->SetX1NDC(0.9); statsPtPPMC->SetX2NDC(0.5);
  statsPtPPMC->SetY1NDC(0.7); statsPtPPMC->SetY2NDC(0.5);
  statsPtPPMC->SetTextColor(kBlue);

  ptMC->Update();

  stackPtMC->GetXaxis()->SetTitle("Transverse momentum of the Z boson candidate, (GeV)");
  stackPtMC->GetYaxis()->SetTitle("Number of particles");

  ptMC->Update();
  ptMC->SaveAs("TransverseMomentumMC.eps");
  ptMC->Modified();

  TCanvas *ptData = new TCanvas;

  THStack *stackPtData = new THStack("stackPtData", "Transverse momentum, Pt, of the Z boson candidates in real collisions");

  TH1F *motherPtPbPbData = (TH1F*)PbPbData->Get("demo/motherPt");
  motherPtPbPbData->SetTitle("Transverse momentum of the Z boson candidates for heavy ion collisions");
  motherPtPbPbData->SetName("Transverse momentum for PbPb data");
  gStyle->SetOptStat(1111);

  TH1F *motherPtPPData = (TH1F*)PPData->Get("demo/motherPt");
  motherPtPPData->SetTitle("Transverse momentum of the Z boson candidates PP data collisions");
  motherPtPPData->SetName("Transverse momentum for PP data");
  gStyle->SetOptStat();

  motherPtPbPbData->SetLineColor(kRed);
  motherPtPPData->SetLineColor(TColor::GetColorDark(kGreen));

  stackPtData->Add(motherPtPbPbData, "sames");
  stackPtData->Add(motherPtPPData, "sames");

  stackPtData->Draw("ehist nostack");

  ptData->Update();

  TPaveStats *statsPtPbPbData = (TPaveStats*)motherPtPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsPtPbPbData->SetX1NDC(0.9); statsPtPbPbData->SetX2NDC(0.5);
  statsPtPbPbData->SetY1NDC(0.9); statsPtPbPbData->SetY2NDC(0.7);
  statsPtPbPbData->SetTextColor(kRed);

  ptData->Update();

  TPaveStats *statsPtPPData = (TPaveStats*)motherPtPPData->GetListOfFunctions()->FindObject("stats"); 
  statsPtPPData->SetX1NDC(0.9); statsPtPPData->SetX2NDC(0.5);
  statsPtPPData->SetY1NDC(0.7); statsPtPPData->SetY2NDC(0.5);
  statsPtPPData->SetTextColor(TColor::GetColorDark(kGreen));

  ptData->Update();

  stackPtData->GetXaxis()->SetTitle("Transverse momentum of the Z boson candidate, (GeV)");
  stackPtData->GetYaxis()->SetTitle("Number of particles");

  ptData->Update();
  ptData->SaveAs("TransverseMomentumData.eps");
  ptData->Modified();

/*-----------------------Eta-----------------------------*/
  TCanvas *etaMC = new TCanvas;
 
  THStack *stackEtaMC = new THStack("stackEtaMC", "Pseudorapidity, eta, of the Z boson candidates in MC simulations");

  TH1F *motherEtaPbPbMC = (TH1F*)PbPbMC->Get("demo/motherEta");
  motherEtaPbPbMC->SetTitle("Pseudorapidity of the Z boson candidates for PbPb MC simulations");
  motherEtaPbPbMC->SetName("Pseudorapidity for PbPb MC");
  gStyle->SetOptStat(1111);

  TH1F *motherEtaPPMC = (TH1F*)PPMC->Get("demo/motherEta");
  motherEtaPPMC->SetTitle("Pseudorapidity of the Z boson candidates in proton-proton MC simulations");
  motherEtaPPMC->SetName("Pseudorapidity for PP MC");
  gStyle->SetOptStat(1111);

  motherEtaPbPbMC->SetLineColor(kBlack);
  motherEtaPPMC->SetLineColor(kBlue);

  stackEtaMC->Add(motherEtaPbPbMC, "sames");
  stackEtaMC->Add(motherEtaPPMC, "sames");

  stackEtaMC->Draw("ehist nostack");

  etaMC->Update();

  TPaveStats *statsEtaPbPbMC = (TPaveStats*)motherEtaPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsEtaPbPbMC->SetX1NDC(0.9); statsEtaPbPbMC->SetX2NDC(0.7);
  statsEtaPbPbMC->SetY1NDC(0.9); statsEtaPbPbMC->SetY2NDC(0.7);
  statsEtaPbPbMC->SetTextColor(kBlack);

  etaMC->Update();

  TPaveStats *statsEtaPPMC = (TPaveStats*)motherEtaPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsEtaPPMC->SetX1NDC(0.9); statsEtaPPMC->SetX2NDC(0.7);
  statsEtaPPMC->SetY1NDC(0.7); statsEtaPPMC->SetY2NDC(0.5);
  statsEtaPPMC->SetTextColor(kBlue);

  etaMC->Update();

  stackEtaMC->GetXaxis()->SetTitle("Pseuorapidity of the Z boson candidate");
  stackEtaMC->GetYaxis()->SetTitle("Number of particles");

  etaMC->Update();
  etaMC->SaveAs("EtaMC.eps");
  etaMC->Modified();

  TCanvas *etaData = new TCanvas;

  THStack *stackEtaData = new THStack("stackEtaData", "Pseudorapidity, eta, of the Z boson candidates in real collisions");
 
  TH1F *motherEtaPbPbData = (TH1F*)PbPbData->Get("demo/motherEta");
  motherEtaPbPbData->SetTitle("Pseudorapidity of the Z boson candidates in heavy ion collisions");
  motherEtaPbPbData->SetName("Pseudorapidity for PbPb data");
  gStyle->SetOptStat(1111);

  TH1F *motherEtaPPData = (TH1F*)PPData->Get("demo/motherEta");
  motherEtaPPData->SetTitle("Pseudorapidity of the Z boson candidates in proton-proton collisions");
  motherEtaPPData->SetName("Pseudorapidity for PP data");
  gStyle->SetOptStat(1111);

  motherEtaPbPbData->SetLineColor(kRed);
  motherEtaPPData->SetLineColor(TColor::GetColorDark(kGreen));

  stackEtaData->Add(motherEtaPbPbData, "sames");
  stackEtaData->Add(motherEtaPPData, "sames");

  stackEtaData->Draw("ehist nostack");

  etaData->Update();

  TPaveStats *statsEtaPbPbData = (TPaveStats*)motherEtaPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsEtaPbPbData->SetX1NDC(0.9); statsEtaPbPbData->SetX2NDC(0.7);
  statsEtaPbPbData->SetY1NDC(0.9); statsEtaPbPbData->SetY2NDC(0.7);
  statsEtaPbPbData->SetTextColor(kRed);

  etaData->Update();

  TPaveStats *statsEtaPPData = (TPaveStats*)motherEtaPPData->GetListOfFunctions()->FindObject("stats"); 
  statsEtaPPData->SetX1NDC(0.9); statsEtaPPData->SetX2NDC(0.7);
  statsEtaPPData->SetY1NDC(0.7); statsEtaPPData->SetY2NDC(0.5);
  statsEtaPPData->SetTextColor(TColor::GetColorDark(kGreen));

  etaData->Update();

  stackEtaData->GetXaxis()->SetTitle("Pseuorapidity of the Z boson candidate");
  stackEtaData->GetYaxis()->SetTitle("Number of particles");

  etaData->Update();
  etaData->SaveAs("EtaData.eps");
  etaData->Modified();

/*-----------------------Theta-----------------------------*/
  TCanvas *thetaMC = new TCanvas;
 
  THStack *stackThetaMC = new THStack("stackThetaMC", "Polar angle, theta, of the Z boson candidates in MC simulations");

  TH1F *motherThetaPbPbMC = (TH1F*)PbPbMC->Get("demo/motherTheta");
  motherThetaPbPbMC->SetTitle("Polar angle of the Z boson candidates for heavy ion MC simulations");
  motherThetaPbPbMC->SetName("Polar angle for PbPb MC");
  gStyle->SetOptStat(1111);

  TH1F *motherThetaPPMC = (TH1F*)PPMC->Get("demo/motherTheta");
  motherThetaPPMC->SetTitle("Polar angle of the Z boson candidates in proton-proton MC simulations");
  motherThetaPPMC->SetName("Polar angle for PP MC");
  gStyle->SetOptStat(1111);

  motherThetaPbPbMC->SetLineColor(kBlack);
  motherThetaPPMC->SetLineColor(kBlue);

  stackThetaMC->Add(motherThetaPbPbMC, "sames");
  stackThetaMC->Add(motherThetaPPMC, "sames");

  stackThetaMC->Draw("ehist nostack");

  thetaMC->Update();

  TPaveStats *statsThetaPbPbMC = (TPaveStats*)motherThetaPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsThetaPbPbMC->SetX1NDC(0.9); statsThetaPbPbMC->SetX2NDC(0.995);
  statsThetaPbPbMC->SetY1NDC(0.9); statsThetaPbPbMC->SetY2NDC(0.7);
  statsThetaPbPbMC->SetTextColor(kBlack);

  thetaMC->Update();

  TPaveStats *statsThetaPPMC = (TPaveStats*)motherThetaPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsThetaPPMC->SetX1NDC(0.9); statsThetaPPMC->SetX2NDC(0.995);
  statsThetaPPMC->SetY1NDC(0.7); statsThetaPPMC->SetY2NDC(0.5);
  statsThetaPPMC->SetTextColor(kBlue);

  thetaMC->Update();

  stackThetaMC->GetXaxis()->SetTitle("Polar angle of the Z boson candidate, (rad)");
  stackThetaMC->GetYaxis()->SetTitle("Number of particles");

  thetaMC->Update();
  thetaMC->SaveAs("ThetaMC.eps");
  thetaMC->Modified();

  TCanvas *thetaData = new TCanvas;

  THStack *stackThetaData = new THStack("stackThetaData", "Polar angle, theta, of the Z boson candidates in real collisions");
 
  TH1F *motherThetaPbPbData = (TH1F*)PbPbData->Get("demo/motherTheta");
  motherThetaPbPbData->SetTitle("Polar angle of the Z boson candidates in heavy ion collisions");
  motherThetaPbPbData->SetName("Polar angle for PbPb data");
  gStyle->SetOptStat(1111);

  TH1F *motherThetaPPData = (TH1F*)PPData->Get("demo/motherTheta");
  motherThetaPPData->SetTitle("Polar angle of the Z boson candidates in proton-proton collisions");
  motherThetaPPData->SetName("Polar angle PP data");  
  gStyle->SetOptStat(1111);

  motherThetaPbPbData->SetLineColor(kRed);
  motherThetaPPData->SetLineColor(TColor::GetColorDark(kGreen));

  stackThetaData->Add(motherThetaPbPbData, "sames");
  stackThetaData->Add(motherThetaPPData, "sames");

  stackThetaData->Draw("ehist nostack");

  thetaData->Update();

  TPaveStats *statsThetaPbPbData = (TPaveStats*)motherThetaPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsThetaPbPbData->SetX1NDC(0.9); statsThetaPbPbData->SetX2NDC(0.995);
  statsThetaPbPbData->SetY1NDC(0.9); statsThetaPbPbData->SetY2NDC(0.7);
  statsThetaPbPbData->SetTextColor(kRed);

  thetaData->Update();

  TPaveStats *statsThetaPPData = (TPaveStats*)motherThetaPPData->GetListOfFunctions()->FindObject("stats"); 
  statsThetaPPData->SetX1NDC(0.9); statsThetaPPData->SetX2NDC(0.995);
  statsThetaPPData->SetY1NDC(0.7); statsThetaPPData->SetY2NDC(0.5);
  statsThetaPPData->SetTextColor(TColor::GetColorDark(kGreen));

  thetaData->Update();

  stackThetaData->GetXaxis()->SetTitle("Polar angle of the Z boson candidate, (rad)");
  stackThetaData->GetYaxis()->SetTitle("Number of particles");

  thetaData->Update();
  thetaData->SaveAs("ThetaData.eps");
  thetaData->Modified();

/*-----------------------Phi-----------------------------*/
  TCanvas *phiMC = new TCanvas;
 
  THStack *stackPhiMC = new THStack("stackPhiMC", "Azimuthal angle, phi, of the Z boson candidates in MC simulations");

  TH1F *motherPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/motherPhi");
  motherPhiPbPbMC->SetTitle("Azimuthal angle of the Z boson candidates for heavy ion MC simulations");
  motherPhiPbPbMC->SetName("Azimuthal angle for PbPb MC");
  gStyle->SetOptStat(1111);

  TH1F *motherPhiPPMC = (TH1F*)PPMC->Get("demo/motherPhi");
  motherPhiPPMC->SetTitle("Azimuthal angle of the Z boson candidates in proton-proton MC simulations");
  motherPhiPPMC->SetName("Azimuthal angle for PP MC"); 
  gStyle->SetOptStat(1111);

  motherPhiPbPbMC->SetLineColor(kBlack);
  motherPhiPPMC->SetLineColor(kBlue);

  stackPhiMC->Add(motherPhiPbPbMC, "sames");
  stackPhiMC->Add(motherPhiPPMC, "sames");

  stackPhiMC->Draw("ehist nostack");

  phiMC->Update();

  TPaveStats *statsPhiPbPbMC = (TPaveStats*)motherPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsPhiPbPbMC->SetX1NDC(0.9); statsPhiPbPbMC->SetX2NDC(0.995);
  statsPhiPbPbMC->SetY1NDC(0.9); statsPhiPbPbMC->SetY2NDC(0.7);
  statsPhiPbPbMC->SetTextColor(kBlack);

  phiMC->Update();

  TPaveStats *statsPhiPPMC = (TPaveStats*)motherPhiPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsPhiPPMC->SetX1NDC(0.9); statsPhiPPMC->SetX2NDC(0.995);
  statsPhiPPMC->SetY1NDC(0.7); statsPhiPPMC->SetY2NDC(0.5);
  statsPhiPPMC->SetTextColor(kBlue);

  phiMC->Update();

  stackPhiMC->GetXaxis()->SetTitle("Azimuthal angle of the Z boson candidate, (rad)");
  stackPhiMC->GetYaxis()->SetTitle("Number of particles");

  phiMC->Update();
  phiMC->SaveAs("PhiMC.eps");
  phiMC->Modified();

  TCanvas *phiData = new TCanvas;

  THStack *stackPhiData = new THStack("stackPhiData", "Azimuthal angle, phi, of the Z boson candidates in real collisions");
 
  TH1F *motherPhiPbPbData = (TH1F*)PbPbData->Get("demo/motherPhi");
  motherPhiPbPbData->SetTitle("Azimuthal angle of the Z boson candidates in heavy ion collisions");
  motherPhiPbPbData->SetName("Azimuthal angle PbPb data");  
  gStyle->SetOptStat(1111);

  TH1F *motherPhiPPData = (TH1F*)PPData->Get("demo/motherPhi");
  motherPhiPPData->SetTitle("Azmiuthal angle of the Z boson candidates in proton-proton collisions");
  motherPhiPPData->SetName("Azimuthal angle PP data");  
  gStyle->SetOptStat(1111);

  motherPhiPbPbData->SetLineColor(kRed);
  motherPhiPPData->SetLineColor(TColor::GetColorDark(kGreen));

  stackPhiData->Add(motherPhiPbPbData, "sames");
  stackPhiData->Add(motherPhiPPData, "sames");

  stackPhiData->Draw("ehist nostack");

  phiData->Update();

  TPaveStats *statsPhiPbPbData = (TPaveStats*)motherPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsPhiPbPbData->SetX1NDC(0.9); statsPhiPbPbData->SetX2NDC(0.995);
  statsPhiPbPbData->SetY1NDC(0.9); statsPhiPbPbData->SetY2NDC(0.7);
  statsPhiPbPbData->SetTextColor(kRed);

  phiData->Update();

  TPaveStats *statsPhiPPData = (TPaveStats*)motherPhiPPData->GetListOfFunctions()->FindObject("stats"); 
  statsPhiPPData->SetX1NDC(0.9); statsPhiPPData->SetX2NDC(0.995);
  statsPhiPPData->SetY1NDC(0.7); statsPhiPPData->SetY2NDC(0.5);
  statsPhiPPData->SetTextColor(TColor::GetColorDark(kGreen));

  phiData->Update();

  stackPhiData->GetXaxis()->SetTitle("Azimuthal angle of the Z boson candidate, (rad)");
  stackPhiData->GetYaxis()->SetTitle("Number of particles");

  phiData->Update();
  phiData->SaveAs("PhiData.eps");
  phiData->Modified();

  /*----------------------- vertex ----------------------*/

  TCanvas *vertexPbPbPrimary = new TCanvas;
  TH3F *primaryPbPb = (TH3F*)PbPbData->Get("demo/primaryVertex");

  TH3F *primaryPbPbData = (TH3F*)primaryPbPb->Clone("Primary Vertex");
  primaryPbPbData->SetName("Primary vertex in PbPb data");
  gStyle->SetOptStat();
  primaryPbPbData->SetMarkerColor(kBlue);
  primaryPbPbData->SetLineColor(kBlue);
  primaryPbPbData->Draw();

  vertexPbPbPrimary->Update();

  TPaveStats *statsVertexPbPbData = (TPaveStats*)primaryPbPbData->FindObject("stats"); 
  statsVertexPbPbData->SetX1NDC(0.9); statsVertexPbPbData->SetX2NDC(0.7);
  statsVertexPbPbData->SetY1NDC(0.9); statsVertexPbPbData->SetY2NDC(0.6);
  statsVertexPbPbData->SetTextColor(kBlue);

  vertexPbPbPrimary->Update();
  vertexPbPbPrimary->Modified();

  TCanvas *vertexPbPbMother = new TCanvas;

  TH3F *motherPbPb = (TH3F*)PbPbData->Get("demo/motherVertex");
  
  TH3F *motherPbPbData = (TH3F*)motherPbPb->Clone("Mother Vertex");
  gStyle->SetOptStat();
  motherPbPbData->SetName("Z candidate vertex in PbPb data");
  motherPbPbData->SetMarkerColor(kRed);
  motherPbPbData->SetLineColor(kRed);
  motherPbPbData->Draw();

  vertexPbPbMother->Update();

  TPaveStats *statsZVertexPbPbData = (TPaveStats*)motherPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsZVertexPbPbData->SetX1NDC(0.9); statsZVertexPbPbData->SetX2NDC(0.7);
  statsZVertexPbPbData->SetY1NDC(0.6); statsZVertexPbPbData->SetY2NDC(0.3);
  statsZVertexPbPbData->SetTextColor(kRed);

  vertexPbPbMother->Update();
  vertexPbPbMother->Modified();

  TCanvas *vertexPbPb = new TCanvas;

  primaryPbPbData->Draw();
  motherPbPbData->Draw("same");
  statsVertexPbPbData->Draw("same");  
  statsZVertexPbPbData->Draw("same");

  vertexPbPb->Update();

  primaryPbPbData->SetTitle("Position of the primary and Z boson vertices in heavy ion collisions");

  primaryPbPbData->GetXaxis()-> SetTitle("X position (cm)");
  primaryPbPbData->GetXaxis()->SetTitleOffset(2);
  primaryPbPbData->GetYaxis()-> SetTitle("Y position (cm)");
  primaryPbPbData->GetYaxis()->SetTitleOffset(2);
  primaryPbPbData->GetZaxis()-> SetTitle("Z position (cm)");

  vertexPbPb->Update();
  vertexPbPb->SaveAs("VertexPbPb.eps");
  vertexPbPb->Modified();

  TCanvas *vertexPPPrimary = new TCanvas;

  TH3F *primaryPP = (TH3F*)PPData->Get("demo/primaryVertex");

  TH3F *primaryPPData = (TH3F*)primaryPP->Clone("Primary Vertex");
  primaryPPData->SetName("Primary vertex in PP data");
  gStyle->SetOptStat();
  primaryPPData->SetMarkerColor(kBlack);
  primaryPPData->SetLineColor(kBlack);
  primaryPPData->Draw();

  vertexPPPrimary->Update();

  TPaveStats *statsVertexPPData = (TPaveStats*)primaryPPData->FindObject("stats"); 
  statsVertexPPData->SetX1NDC(0.9); statsVertexPPData->SetX2NDC(0.7);
  statsVertexPPData->SetY1NDC(0.9); statsVertexPPData->SetY2NDC(0.6);
  statsVertexPPData->SetTextColor(kBlack);

  vertexPPPrimary->Update();
  vertexPPPrimary->Modified();

  TCanvas *vertexPPMother = new TCanvas;

  TH3F *motherPP = (TH3F*)PPData->Get("demo/motherVertex");
  
  TH3F *motherPPData = (TH3F*)motherPP->Clone("Mother Vertex");
  gStyle->SetOptStat();
  motherPPData->SetName("Z candidate vertex in PP data");
  motherPPData->SetMarkerColor(TColor::GetColorDark(kGreen));
  motherPPData->SetLineColor(TColor::GetColorDark(kGreen));
  motherPPData->Draw();

  vertexPPMother->Update();

  TPaveStats *statsZVertexPPData = (TPaveStats*)motherPPData->GetListOfFunctions()->FindObject("stats"); 
  statsZVertexPPData->SetX1NDC(0.9); statsZVertexPPData->SetX2NDC(0.7);
  statsZVertexPPData->SetY1NDC(0.6); statsZVertexPPData->SetY2NDC(0.3);
  statsZVertexPPData->SetTextColor(TColor::GetColorDark(kGreen));

  vertexPPMother->Update();
  vertexPPMother->Modified();

  TCanvas *vertexPP = new TCanvas;  
 
  primaryPPData->Draw();
  motherPPData->Draw("same");
  statsVertexPPData->Draw("same");
  statsZVertexPPData->Draw("same");
  
  primaryPPData->SetTitle("Position of the primary and Z boson vertices in proton-proton collisions");

  primaryPPData->GetXaxis()-> SetTitle("X position (cm)");
  primaryPPData->GetXaxis()->SetTitleOffset(2);
  primaryPPData->GetYaxis()-> SetTitle("Y position (cm)");
  primaryPPData->GetYaxis()->SetTitleOffset(2);
  primaryPPData->GetZaxis()-> SetTitle("Z position (cm)");

  vertexPP->Update();
  vertexPP->SaveAs("VertexPP.eps");
  vertexPP->Modified();

  /*------------------Jet-Z ratio R=0.3 ---------------------*/
  TCanvas *ratio330PbPbMC = new TCanvas("ratio3", "R=0.3 Ratio of Jet-Z Pt", 10,10,700,700);

  TH1F *jetZ330RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet3Z30Ratio");
  jetZ330RatioPbPbMC->SetTitle("Z Pt>30GeV, R=0.3, Jet-Z pt ratio for heavy ion MC simulations");
  jetZ330RatioPbPbMC->SetXTitle("Ratio");
  jetZ330RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
  jetZ330RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
  gStyle->SetOptFit(1111);
  ratio330PbPbMC->Update();

   TH1F *jetZ330RatioPbPbMC1 = (TH1F*)jetZ330RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   TF1 *gaus    = new TF1("gaus","gaus", 0,1.8);
   gaus->SetLineColor(kBlack);    
   jetZ330RatioPbPbMC1->Fit(gaus);
   ratio330PbPbMC->Update();
   
   TPaveStats *ratioStats330PbPbMC = (TPaveStats*)jetZ330RatioPbPbMC1->FindObject("stats");
   ratioStats330PbPbMC->SetX1NDC(0.9);
   ratioStats330PbPbMC->SetX2NDC(0.5);
   ratioStats330PbPbMC->SetY1NDC(0.9);
   ratioStats330PbPbMC->SetY2NDC(0.5);
   ratioStats330PbPbMC->SetTextColor(kBlack);

   ratio330PbPbMC->Update();
   ratio330PbPbMC->SaveAs("Ratio330PbPbMC.eps");
   ratio330PbPbMC->Modified();

   TCanvas *ratio360PbPbMC = new TCanvas;
  
   TH1F *jetZ360RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet3Z60Ratio");
   jetZ360RatioPbPbMC->SetTitle("Z Pt>60GeV, R=0.3, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ360RatioPbPbMC->SetXTitle("Ratio");
   jetZ360RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ360RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio360PbPbMC->Update();

   TH1F *jetZ360RatioPbPbMC1 = (TH1F*)jetZ360RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");   
   jetZ360RatioPbPbMC1->Fit(gaus);
   ratio360PbPbMC->Update();
   
   TPaveStats *ratioStats360PbPbMC = (TPaveStats*)jetZ360RatioPbPbMC1->FindObject("stats");
   ratioStats360PbPbMC->SetX1NDC(0.9);
   ratioStats360PbPbMC->SetX2NDC(0.5);
   ratioStats360PbPbMC->SetY1NDC(0.9);
   ratioStats360PbPbMC->SetY2NDC(0.5);
   ratioStats360PbPbMC->SetTextColor(kBlack);

   ratio360PbPbMC->Update();
   ratio360PbPbMC->SaveAs("Ratio360PbPbMC.eps");
   ratio360PbPbMC->Modified();

   TCanvas * ratio3100PbPbMC = new TCanvas;

   TH1F *jetZ3100RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet3Z100Ratio");
   jetZ3100RatioPbPbMC->SetTitle("Z Pt>100GeV, R=0.3, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ3100RatioPbPbMC->SetXTitle("Ratio");
   jetZ3100RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ3100RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio3100PbPbMC->Update();

   TH1F *jetZ3100RatioPbPbMC1 = (TH1F*)jetZ3100RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   TF1 *gausFit1 = new TF1("gausFit1","gaus",0,0.5);
   TF1 *gausFit2 = new TF1("gausFit2","gaus",0.5,1.8);
   gausFit1->SetLineColor(kBlack); 
   gausFit2->SetLineColor(kBlack);
   jetZ3100RatioPbPbMC1->Fit(gausFit1,"R");
   jetZ3100RatioPbPbMC1->Fit(gausFit2,"R+", "sames");
   ratio3100PbPbMC->Update();

   TPaveStats *ratioStats3100PbPbMC1 = (TPaveStats*)jetZ3100RatioPbPbMC1->FindObject("stats");
   ratioStats3100PbPbMC1->SetX1NDC(0.9);
   ratioStats3100PbPbMC1->SetX2NDC(0.5);
   ratioStats3100PbPbMC1->SetY1NDC(0.9);
   ratioStats3100PbPbMC1->SetY2NDC(0.5);
   ratioStats3100PbPbMC1->SetTextColor(kBlack);
  
   ratio3100PbPbMC->Update();  
   ratio3100PbPbMC->SaveAs("Ratio3100PbPbMC.eps");
   ratio3100PbPbMC->Modified();

   TCanvas *ratio330PbPbData = new TCanvas;

   TH1F *jetZ330RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet3Z30Ratio");
   jetZ330RatioPbPbData->SetTitle("Z Pt>30GeV, R=0.3, Jet-Z pt ratio for heavy ion data");
   jetZ330RatioPbPbData->SetXTitle("Ratio");
   jetZ330RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ330RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio330PbPbData->Update();
   
   TH1F *jetZ330RatioPbPbData1 = (TH1F*)jetZ330RatioPbPbData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ330RatioPbPbData1->Fit(gaus);
   ratio330PbPbData->Update();
   
   TPaveStats *ratioStats330PbPbData = (TPaveStats*)jetZ330RatioPbPbData1->FindObject("stats");
   ratioStats330PbPbData->SetX1NDC(0.9);
   ratioStats330PbPbData->SetX2NDC(0.5);
   ratioStats330PbPbData->SetY1NDC(0.9);
   ratioStats330PbPbData->SetY2NDC(0.5);
   ratioStats330PbPbData->SetTextColor(kBlack);

   ratio330PbPbData->Update();
   ratio330PbPbData->SaveAs("Ratio330PbPbData.eps");
   ratio330PbPbData->Modified();

   TCanvas *ratio360PbPbData = new TCanvas;

   TH1F *jetZ360RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet3Z60Ratio");
   jetZ360RatioPbPbData->SetTitle("Z Pt>60GeV, R=0.3, Jet-Z pt ratio for heavy ion data");
   jetZ360RatioPbPbData->SetXTitle("Ratio");
   jetZ360RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ360RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio360PbPbData->Update();

   TH1F *jetZ360RatioPbPbData1 = (TH1F*)jetZ360RatioPbPbData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ360RatioPbPbData1->Fit(gaus);
   ratio360PbPbData->Update();
   
   TPaveStats *ratioStats360PbPbData = (TPaveStats*)jetZ360RatioPbPbData1->FindObject("stats");
   ratioStats360PbPbData->SetX1NDC(0.9);
   ratioStats360PbPbData->SetX2NDC(0.5);
   ratioStats360PbPbData->SetY1NDC(0.9);
   ratioStats360PbPbData->SetY2NDC(0.5);
   ratioStats360PbPbData->SetTextColor(kBlack);

   ratio360PbPbData->Update();
   ratio360PbPbData->SaveAs("Ratio360PbPbData.eps");
   ratio360PbPbData->Modified();

   TCanvas *ratio3100PbPbData = new TCanvas;

   TH1F *jetZ3100RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet3Z100Ratio");
   jetZ3100RatioPbPbData->SetTitle("Z Pt>100GeV, R=0.3, Jet-Z pt ratio for heavy ion data");
   jetZ3100RatioPbPbData->SetXTitle("Ratio");
   jetZ3100RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ3100RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   jetZ3100RatioPbPbData->Draw();
   ratio3100PbPbData->Update();
   
   TPaveStats *ratioStats3100PbPbData = (TPaveStats*)jetZ3100RatioPbPbData->FindObject("stats");
   ratioStats3100PbPbData->SetX1NDC(0.9);
   ratioStats3100PbPbData->SetX2NDC(0.5);
   ratioStats3100PbPbData->SetY1NDC(0.9);
   ratioStats3100PbPbData->SetY2NDC(0.5);
   ratioStats3100PbPbData->SetTextColor(kBlack);
   ratio3100PbPbData->Update();

   ratio3100PbPbData->SaveAs("Ratio3100PbPbData.eps");
   ratio3100PbPbData->Modified();

/*------------------Jet-Z ratio R=0.4 ---------------------*/
   TCanvas *ratio430PbPbMC = new TCanvas("ratio4PbPb", "R=0.4 Ratio of Jet-Z Pt", 10,10,700,700);

   TH1F *jetZ430RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet4Z30Ratio");
   jetZ430RatioPbPbMC->SetTitle("Z Pt>30GeV, R=0.4, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ430RatioPbPbMC->SetXTitle("Ratio");
   jetZ430RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ430RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio430PbPbMC->Update();

   TH1F *jetZ430RatioPbPbMC1 = (TH1F*)jetZ430RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   jetZ430RatioPbPbMC1->Fit(gaus);
   ratio430PbPbMC->Update();
   
   TPaveStats *ratioStats430PbPbMC = (TPaveStats*)jetZ430RatioPbPbMC1->FindObject("stats");
   ratioStats430PbPbMC->SetX1NDC(0.9);
   ratioStats430PbPbMC->SetX2NDC(0.5);
   ratioStats430PbPbMC->SetY1NDC(0.9);
   ratioStats430PbPbMC->SetY2NDC(0.5);
   ratioStats430PbPbMC->SetTextColor(kBlack);
   
   ratio430PbPbMC->Update();
   ratio430PbPbMC->SaveAs("ratio430PbPbMC.eps");
   ratio430PbPbMC->Modified();

   TCanvas *ratio460PbPbMC = new TCanvas;

   TH1F *jetZ460RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet4Z60Ratio");
   jetZ460RatioPbPbMC->SetTitle("Z Pt>60GeV, R=0.4, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ460RatioPbPbMC->SetXTitle("Ratio");
   jetZ460RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ460RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio460PbPbMC->Update();

   TH1F *jetZ460RatioPbPbMC1 = (TH1F*)jetZ460RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ460RatioPbPbMC1->Fit(gaus);
   ratio460PbPbMC->Update();
   
   TPaveStats *ratioStats460PbPbMC = (TPaveStats*)jetZ460RatioPbPbMC1->FindObject("stats");
   ratioStats460PbPbMC->SetX1NDC(0.9);
   ratioStats460PbPbMC->SetX2NDC(0.5);
   ratioStats460PbPbMC->SetY1NDC(0.9);
   ratioStats460PbPbMC->SetY2NDC(0.5);
   ratioStats460PbPbMC->SetTextColor(kBlack);

   ratio460PbPbMC->Update();
   ratio460PbPbMC->SaveAs("ratio460PbPbMC.eps");
   ratio460PbPbMC->Modified();

   TCanvas *ratio4100PbPbMC = new TCanvas;

   TH1F *jetZ4100RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet4Z100Ratio");
   jetZ4100RatioPbPbMC->SetTitle("Z Pt>100GeV, R=0.4, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ4100RatioPbPbMC->SetXTitle("Ratio");
   jetZ4100RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ4100RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio4100PbPbMC->Update();

   TH1F *jetZ4100RatioPbPbMC1 = (TH1F*)jetZ4100RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   jetZ4100RatioPbPbMC1->Fit(gausFit1,"R");
   jetZ4100RatioPbPbMC1->Fit(gausFit2,"R+", "sames");
   ratio4100PbPbMC->Update();

   TPaveStats *ratioStats4100PbPbMC1 = (TPaveStats*)jetZ4100RatioPbPbMC1->FindObject("stats");
   ratioStats4100PbPbMC1->SetX1NDC(0.9);
   ratioStats4100PbPbMC1->SetX2NDC(0.5);
   ratioStats4100PbPbMC1->SetY1NDC(0.9);
   ratioStats4100PbPbMC1->SetY2NDC(0.5);
   ratioStats4100PbPbMC1->SetTextColor(kBlack);

   ratio4100PbPbMC->Update();  
   ratio4100PbPbMC->SaveAs("ratio4100PbPbMC.eps");
   ratio4100PbPbMC->Modified();

   TCanvas *ratio430PbPbData = new TCanvas;

   TH1F *jetZ430RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet4Z30Ratio");
   jetZ430RatioPbPbData->SetTitle("Z Pt>30GeV, R=0.4, Jet-Z pt ratio for heavy ion data");
   jetZ430RatioPbPbData->SetXTitle("Ratio");
   jetZ430RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ430RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio430PbPbData->Update();

   TH1F *jetZ430RatioPbPbData1 = (TH1F*)jetZ430RatioPbPbData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ430RatioPbPbData1->Fit(gaus);
   ratio430PbPbData->Update();
   
   TPaveStats *ratioStats430PbPbData = (TPaveStats*)jetZ430RatioPbPbData1->FindObject("stats");
   ratioStats430PbPbData->SetX1NDC(0.9);
   ratioStats430PbPbData->SetX2NDC(0.5);
   ratioStats430PbPbData->SetY1NDC(0.9);
   ratioStats430PbPbData->SetY2NDC(0.5);
   ratioStats430PbPbData->SetTextColor(kBlack);

   ratio430PbPbData->Update();
   ratio430PbPbData->SaveAs("ratio430PbPbData.eps");
   ratio430PbPbData->Modified();

   TCanvas *ratio460PbPbData = new TCanvas;

   TH1F *jetZ460RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet4Z60Ratio");
   jetZ460RatioPbPbData->SetTitle("Z Pt>60GeV, R=0.4, Jet-Z pt ratio for heavy ion data");
   jetZ460RatioPbPbData->SetXTitle("Ratio");
   jetZ460RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ460RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio460PbPbData->Update();
   
   TH1F *jetZ460RatioPbPbData1 = (TH1F*)jetZ460RatioPbPbData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ460RatioPbPbData1->Fit(gaus);
   ratio460PbPbData->Update();
   
   TPaveStats *ratioStats460PbPbData = (TPaveStats*)jetZ460RatioPbPbData1->FindObject("stats");
   ratioStats460PbPbData->SetX1NDC(0.9);
   ratioStats460PbPbData->SetX2NDC(0.5);
   ratioStats460PbPbData->SetY1NDC(0.9);
   ratioStats460PbPbData->SetY2NDC(0.5);
   ratioStats460PbPbData->SetTextColor(kBlack);
   
   ratio460PbPbData->Update();
   ratio460PbPbData->SaveAs("ratio460PbPbData.eps");
   ratio460PbPbData->Modified();

   TCanvas *ratio4100PbPbData = new TCanvas;

   TH1F *jetZ4100RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet4Z100Ratio");
   jetZ4100RatioPbPbData->SetTitle("Z Pt>100GeV, R=0.4, Jet-Z pt ratio for heavy ion data");
   jetZ4100RatioPbPbData->SetXTitle("Ratio");
   jetZ4100RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ4100RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   jetZ4100RatioPbPbData->Draw();
   ratio4100PbPbData->Update();
   
   TPaveStats *ratioStats4100PbPbData = (TPaveStats*)jetZ4100RatioPbPbData->FindObject("stats");
   ratioStats4100PbPbData->SetX1NDC(0.9);
   ratioStats4100PbPbData->SetX2NDC(0.5);
   ratioStats4100PbPbData->SetY1NDC(0.9);
   ratioStats4100PbPbData->SetY2NDC(0.5);
   ratioStats4100PbPbData->SetTextColor(kBlack);
   
   ratio4100PbPbData->Update(); 
   ratio4100PbPbData->SaveAs("Ratio4100PbPbData.eps");
   ratio4100PbPbData->Modified();

/*------------------Jet-Z ratio R=0.4 ---------------------*/
   TCanvas *ratio430PPMC = new TCanvas("ratio4PP", "R=0.4 Ratio of Jet-Z Pt", 10,10,700,700);

   TH1F *jetZ430RatioPPMC = (TH1F*)PPMC->Get("demo/jet4Z30Ratio");
   jetZ430RatioPPMC->SetTitle("Z Pt>30GeV, R=0.4, Jet-Z pt ratio for proton-proton MC simulations");
   jetZ430RatioPPMC->SetXTitle("Ratio");
   jetZ430RatioPPMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ430RatioPPMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio430PPMC->Update();

   TH1F *jetZ430RatioPPMC1 = (TH1F*)jetZ430RatioPPMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   jetZ430RatioPPMC1->Fit(gaus);
   ratio430PPMC->Update();
   
   TPaveStats *ratioStats430PPMC = (TPaveStats*)jetZ430RatioPPMC1->FindObject("stats");
   ratioStats430PPMC->SetX1NDC(0.9);
   ratioStats430PPMC->SetX2NDC(0.5);
   ratioStats430PPMC->SetY1NDC(0.9);
   ratioStats430PPMC->SetY2NDC(0.5);
   ratioStats430PPMC->SetTextColor(kBlack);
  
   ratio430PPMC->Update();
   ratio430PPMC->SaveAs("ratio430PPMC.eps");
   ratio430PPMC->Modified();

   TCanvas *ratio460PPMC = new TCanvas;

   TH1F *jetZ460RatioPPMC = (TH1F*)PPMC->Get("demo/jet4Z60Ratio");
   jetZ460RatioPPMC->SetTitle("Z Pt>60GeV, R=0.4, Jet-Z pt ratio for proton-proton MC simulations");
   jetZ460RatioPPMC->SetXTitle("Ratio");
   jetZ460RatioPPMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ460RatioPPMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio460PPMC->Update();

   TH1F *jetZ460RatioPPMC1 = (TH1F*)jetZ460RatioPPMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ460RatioPPMC1->Fit(gaus);
   ratio460PPMC->Update();
   
   TPaveStats *ratioStats460PPMC = (TPaveStats*)jetZ460RatioPPMC1->FindObject("stats");
   ratioStats460PPMC->SetX1NDC(0.9);
   ratioStats460PPMC->SetX2NDC(0.5);
   ratioStats460PPMC->SetY1NDC(0.9);
   ratioStats460PPMC->SetY2NDC(0.5);
   ratioStats460PPMC->SetTextColor(kBlack);
  
   ratio460PPMC->Update();
   ratio460PPMC->SaveAs("ratio460PPMC.eps");
   ratio460PPMC->Modified();

   TCanvas *ratio4100PPMC = new TCanvas;

   TH1F *jetZ4100RatioPPMC = (TH1F*)PPMC->Get("demo/jet4Z100Ratio");
   jetZ4100RatioPPMC->SetTitle("Z Pt>100GeV, R=0.4, Jet-Z pt ratio for proton-proton MC simulations");
   jetZ4100RatioPPMC->SetXTitle("Ratio");
   jetZ4100RatioPPMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ4100RatioPPMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio4100PPMC->Update();

   TH1F *jetZ4100RatioPPMC1 = (TH1F*)jetZ4100RatioPPMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   jetZ4100RatioPPMC1->Fit(gaus);
   ratio4100PPMC->Update();

   TPaveStats *ratioStats4100PPMC1 = (TPaveStats*)jetZ4100RatioPPMC1->FindObject("stats");
   ratioStats4100PPMC1->SetX1NDC(0.9);
   ratioStats4100PPMC1->SetX2NDC(0.5);
   ratioStats4100PPMC1->SetY1NDC(0.9);
   ratioStats4100PPMC1->SetY2NDC(0.5);
   ratioStats4100PPMC1->SetTextColor(kBlack);

   ratio4100PPMC->Update();  
   ratio4100PPMC->SaveAs("ratio4100PPMC.eps");
   ratio4100PPMC->Modified();

   TCanvas *ratio430PPData = new TCanvas;

   TH1F *jetZ430RatioPPData = (TH1F*)PPData->Get("demo/jet4Z30Ratio");
   jetZ430RatioPPData->SetTitle("Z Pt>30GeV, R=0.4, Jet-Z pt ratio for proton-proton data");
   jetZ430RatioPPData->SetXTitle("Ratio");
   jetZ430RatioPPData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ430RatioPPData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio430PPData->Update();

   TH1F *jetZ430RatioPPData1 = (TH1F*)jetZ430RatioPPData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ430RatioPPData1->Fit(gaus);
   ratio430PPData->Update();
   
   TPaveStats *ratioStats430PPData = (TPaveStats*)jetZ430RatioPPData1->FindObject("stats");
   ratioStats430PPData->SetX1NDC(0.9);
   ratioStats430PPData->SetX2NDC(0.5);
   ratioStats430PPData->SetY1NDC(0.9);
   ratioStats430PPData->SetY2NDC(0.5);
   ratioStats430PPData->SetTextColor(kBlack);

   ratio430PPData->Update();
   ratio430PPData->SaveAs("ratio430PPData.eps");
   ratio430PPData->Modified();

   TCanvas *ratio460PPData = new TCanvas;

   TH1F *jetZ460RatioPPData = (TH1F*)PPData->Get("demo/jet4Z60Ratio");
   jetZ460RatioPPData->SetTitle("Z Pt>60GeV, R=0.4, Jet-Z pt ratio for proton-proton data");
   jetZ460RatioPPData->SetXTitle("Ratio");
   jetZ460RatioPPData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ460RatioPPData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio460PPData->Update();
   
   TH1F *jetZ460RatioPPData1 = (TH1F*)jetZ460RatioPPData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ460RatioPPData1->Fit(gaus);
   ratio460PPData->Update();
   
   TPaveStats *ratioStats460PPData = (TPaveStats*)jetZ460RatioPPData1->FindObject("stats");
   ratioStats460PPData->SetX1NDC(0.9);
   ratioStats460PPData->SetX2NDC(0.5);
   ratioStats460PPData->SetY1NDC(0.9);
   ratioStats460PPData->SetY2NDC(0.5);
   ratioStats460PPData->SetTextColor(kBlack);

   ratio460PPData->Update();
   ratio460PPData->SaveAs("ratio460PPData.eps");
   ratio460PPData->Modified();

   TCanvas *ratio4100PPData = new TCanvas;

   TH1F *jetZ4100RatioPPData = (TH1F*)PPData->Get("demo/jet4Z100Ratio");
   jetZ4100RatioPPData->SetTitle("Z Pt>100GeV, R=0.4, Jet-Z pt ratio for proton-proton data");
   jetZ4100RatioPPData->SetXTitle("Ratio");
   jetZ4100RatioPPData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ4100RatioPPData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   jetZ4100RatioPPData->Draw();
   ratio4100PPData->Update();
   
   TPaveStats *ratioStats4100PPData = (TPaveStats*)jetZ4100RatioPPData->FindObject("stats");
   ratioStats4100PPData->SetX1NDC(0.9);
   ratioStats4100PPData->SetX2NDC(0.5);
   ratioStats4100PPData->SetY1NDC(0.9);
   ratioStats4100PPData->SetY2NDC(0.5);
   ratioStats4100PPData->SetTextColor(kBlack);

   ratio4100PPData->Update();
   ratio4100PPData->SaveAs("Ratio4100PPData.eps");
   ratio4100PPData->Modified(); 

/*------------------Jet-Z ratio R=0.5 ---------------------*/
   TCanvas *ratio530PbPbMC = new TCanvas("ratio5", "R=0.5 Ratio of Jet-Z Pt", 10,10,700,700);

   TH1F *jetZ530RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet5Z30Ratio");
   jetZ530RatioPbPbMC->SetTitle("Z Pt>30GeV, R=0.5, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ530RatioPbPbMC->SetXTitle("Ratio");
   jetZ530RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ530RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio530PbPbMC->Update();

   TH1F *jetZ530RatioPbPbMC1 = (TH1F*)jetZ530RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   jetZ530RatioPbPbMC1->Fit(gaus);
   ratio530PbPbMC->Update();
   
   TPaveStats *ratioStats530PbPbMC = (TPaveStats*)jetZ530RatioPbPbMC1->FindObject("stats");
   ratioStats530PbPbMC->SetX1NDC(0.9);
   ratioStats530PbPbMC->SetX2NDC(0.5);
   ratioStats530PbPbMC->SetY1NDC(0.9);
   ratioStats530PbPbMC->SetY2NDC(0.5);
   ratioStats530PbPbMC->SetTextColor(kBlack);

   ratio530PbPbMC->Update();
   ratio530PbPbMC->SaveAs("ratio530PbPbMC.eps");
   ratio530PbPbMC->Modified();

   TCanvas *ratio560PbPbMC = new TCanvas;

   TH1F *jetZ560RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet5Z60Ratio");
   jetZ560RatioPbPbMC->SetTitle("Z Pt>60GeV, R=0.5, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ560RatioPbPbMC->SetXTitle("Ratio");
   jetZ560RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ560RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio560PbPbMC->Update();

   TH1F *jetZ560RatioPbPbMC1 = (TH1F*)jetZ560RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ560RatioPbPbMC1->Fit(gaus);
   ratio560PbPbMC->Update();
   
   TPaveStats *ratioStats560PbPbMC = (TPaveStats*)jetZ560RatioPbPbMC1->FindObject("stats");
   ratioStats560PbPbMC->SetX1NDC(0.9);
   ratioStats560PbPbMC->SetX2NDC(0.5);
   ratioStats560PbPbMC->SetY1NDC(0.9);
   ratioStats560PbPbMC->SetY2NDC(0.5);
   ratioStats560PbPbMC->SetTextColor(kBlack);
  
   ratio560PbPbMC->Update();
   ratio560PbPbMC->SaveAs("ratio560PbPbMC.eps");
   ratio560PbPbMC->Modified();

   TCanvas *ratio5100PbPbMC = new TCanvas;

   TH1F *jetZ5100RatioPbPbMC = (TH1F*)PbPbMC->Get("demo/jet5Z100Ratio");
   jetZ5100RatioPbPbMC->SetTitle("Z Pt>100GeV, R=0.5, Jet-Z pt ratio for heavy ion MC simulations");
   jetZ5100RatioPbPbMC->SetXTitle("Ratio");
   jetZ5100RatioPbPbMC->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ5100RatioPbPbMC->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio5100PbPbMC->Update();

   TH1F *jetZ5100RatioPbPbMC1 = (TH1F*)jetZ5100RatioPbPbMC->Clone("Fitted with Gaussian distribution over the range of 0-1.8");
   jetZ5100RatioPbPbMC1->Fit(gausFit1,"R");
   jetZ5100RatioPbPbMC1->Fit(gausFit2,"R+", "sames");
   ratio5100PbPbMC->Update();

   TPaveStats *ratioStats5100PbPbMC1 = (TPaveStats*)jetZ5100RatioPbPbMC1->FindObject("stats");
   ratioStats5100PbPbMC1->SetX1NDC(0.9);
   ratioStats5100PbPbMC1->SetX2NDC(0.5);
   ratioStats5100PbPbMC1->SetY1NDC(0.9);
   ratioStats5100PbPbMC1->SetY2NDC(0.5);
   ratioStats5100PbPbMC1->SetTextColor(kBlack);
   
   ratio5100PbPbMC->Update();  
   ratio5100PbPbMC->SaveAs("ratio5100PbPbMC.eps");
   ratio5100PbPbMC->Modified();

   TCanvas *ratio530PbPbData = new TCanvas;

   TH1F *jetZ530RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet5Z30Ratio");
   jetZ530RatioPbPbData->SetTitle("Z Pt>30GeV, R=0.5, Jet-Z pt ratio for heavy ion data");
   jetZ530RatioPbPbData->SetXTitle("Ratio");
   jetZ530RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ530RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio530PbPbData->Update();

   TH1F *jetZ530RatioPbPbData1 = (TH1F*)jetZ530RatioPbPbData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ530RatioPbPbData1->Fit(gaus);
   ratio530PbPbData->Update();
   
   TPaveStats *ratioStats530PbPbData = (TPaveStats*)jetZ530RatioPbPbData1->FindObject("stats");
   ratioStats530PbPbData->SetX1NDC(0.9);
   ratioStats530PbPbData->SetX2NDC(0.5);
   ratioStats530PbPbData->SetY1NDC(0.9);
   ratioStats530PbPbData->SetY2NDC(0.5);
   ratioStats530PbPbData->SetTextColor(kBlack);
   
   ratio530PbPbData->Update();
   ratio530PbPbData->SaveAs("ratio530PbPbData.eps");
   ratio530PbPbData->Modified();

   TCanvas *ratio560PbPbData = new TCanvas;

   TH1F *jetZ560RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet5Z60Ratio");
   jetZ560RatioPbPbData->SetTitle("Z Pt>60GeV, R=0.5, Jet-Z pt ratio for heavy ion data");
   jetZ560RatioPbPbData->SetXTitle("Ratio");
   jetZ560RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ560RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   ratio560PbPbData->Update();

   TH1F *jetZ560RatioPbPbData1 = (TH1F*)jetZ560RatioPbPbData->Clone("Fitted with Gaussian distribution over the range of 0-1.8"); 
   jetZ560RatioPbPbData1->Fit(gaus);
   ratio560PbPbData->Update();
   
   TPaveStats *ratioStats560PbPbData = (TPaveStats*)jetZ560RatioPbPbData1->FindObject("stats");
   ratioStats560PbPbData->SetX1NDC(0.9);
   ratioStats560PbPbData->SetX2NDC(0.5);
   ratioStats560PbPbData->SetY1NDC(0.9);
   ratioStats560PbPbData->SetY2NDC(0.5);
   ratioStats560PbPbData->SetTextColor(kBlack);
   
   ratio560PbPbData->Update();
   ratio560PbPbData->SaveAs("ratio560PbPbData.eps");
   ratio560PbPbData->Modified();

   TCanvas *ratio5100PbPbData = new TCanvas;

   TH1F *jetZ5100RatioPbPbData = (TH1F*)PbPbData->Get("demo/jet5Z100Ratio");
   jetZ5100RatioPbPbData->SetTitle("Z Pt>100GeV, R=0.5, Jet-Z pt ratio for heavy ion data");
   jetZ5100RatioPbPbData->SetXTitle("Ratio");
   jetZ5100RatioPbPbData->SetYTitle("Number of back-to-back Jet-Z events");
   jetZ5100RatioPbPbData->GetYaxis()->SetTitleOffset(1.5);
   gStyle->SetOptFit(1111);
   jetZ5100RatioPbPbData->Draw();
   ratio5100PbPbData->Update();
   
   TPaveStats *ratioStats5100PbPbData = (TPaveStats*)jetZ5100RatioPbPbData->FindObject("stats");
   ratioStats5100PbPbData->SetX1NDC(0.9);
   ratioStats5100PbPbData->SetX2NDC(0.5);
   ratioStats5100PbPbData->SetY1NDC(0.9);
   ratioStats5100PbPbData->SetY2NDC(0.5);
   ratioStats5100PbPbData->SetTextColor(kBlack);
   
   ratio5100PbPbData->Update(); 
   ratio5100PbPbData->SaveAs("ratio5100PbPbData.eps");
   ratio5100PbPbData->Modified();

/*------------------Jet-Z dPhi ---------------------*/
   TCanvas *dPhiPbPb30MC = new TCanvas("dPhiPbPb", "Jet-Z azimuthal angle difference", 10,10,700,700);

   THStack *stackdPhiPbPb30MC = new THStack("stackdPhiPbPb30MC", "Z Pt>30GeV, Jet-Z azimuthal angle difference in heavy ion MC simulations");

   TH1F *jetZ330dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet3dPhiHisto");
   jetZ330dPhiPbPbMC->SetName("R = 0.3");
   gStyle->SetOptStat(1111);

   TH1F *jetZ430dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet4dPhiHisto");
   jetZ430dPhiPbPbMC->SetName("R = 0.4");
   gStyle->SetOptStat(1111);

   TH1F *jetZ530dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet5dPhiHisto");
   jetZ530dPhiPbPbMC->SetName("R = 0.5");
   gStyle->SetOptStat(1111);

   jetZ330dPhiPbPbMC->SetLineColor(kRed);
   jetZ430dPhiPbPbMC->SetLineColor(TColor::GetColorDark(kGreen));
   jetZ530dPhiPbPbMC->SetLineColor(kBlue);

   stackdPhiPbPb30MC->Add(jetZ330dPhiPbPbMC, "sames");
   stackdPhiPbPb30MC->Add(jetZ430dPhiPbPbMC, "sames");
   stackdPhiPbPb30MC->Add(jetZ530dPhiPbPbMC, "sames");

   stackdPhiPbPb30MC->Draw("ehist nostack");

   dPhiPbPb30MC->Update();

  TPaveStats *statsdPhi330PbPbMC = (TPaveStats*)jetZ330dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi330PbPbMC->SetX1NDC(0.9); statsdPhi330PbPbMC->SetX2NDC(0.65);
  statsdPhi330PbPbMC->SetY1NDC(0.9); statsdPhi330PbPbMC->SetY2NDC(0.7);
  statsdPhi330PbPbMC->SetTextColor(kRed);

  dPhiPbPb30MC->Update();

  TPaveStats *statsdPhi430PbPbMC = (TPaveStats*)jetZ430dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi430PbPbMC->SetX1NDC(0.9); statsdPhi430PbPbMC->SetX2NDC(0.65);
  statsdPhi430PbPbMC->SetY1NDC(0.7); statsdPhi430PbPbMC->SetY2NDC(0.5);
  statsdPhi430PbPbMC->SetTextColor(TColor::GetColorDark(kGreen));

  dPhiPbPb30MC->Update();

  TPaveStats *statsdPhi530PbPbMC = (TPaveStats*)jetZ530dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi530PbPbMC->SetX1NDC(0.9); statsdPhi530PbPbMC->SetX2NDC(0.65);
  statsdPhi530PbPbMC->SetY1NDC(0.5); statsdPhi530PbPbMC->SetY2NDC(0.3);
  statsdPhi530PbPbMC->SetTextColor(kBlue);

  dPhiPbPb30MC->Update();

  stackdPhiPbPb30MC->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPbPb30MC->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPbPb30MC->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPbPb30MC->GetYaxis()->SetTitleOffset(1.5);
  
  dPhiPbPb30MC->Update();
  dPhiPbPb30MC->SaveAs("dPhiPbPb30MC.eps");
  dPhiPbPb30MC->Modified();

  TCanvas *dPhiPbPb60MC = new TCanvas;  

  THStack *stackdPhiPbPb60MC = new THStack("stackdPhiPbPb60MC", "Z Pt>60GeV, Jet-Z azimuthal angle difference in heavy ion MC simulations");

  TH1F *jetZ360dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet360dPhiHisto");
  jetZ360dPhiPbPbMC->SetName("R = 0.3");
  gStyle->SetOptStat(1111);
  
  TH1F *jetZ460dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet460dPhiHisto");
  jetZ460dPhiPbPbMC->SetName("R = 0.4");  
  gStyle->SetOptStat(1111);

  TH1F *jetZ560dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet560dPhiHisto");
  jetZ560dPhiPbPbMC->SetName("R = 0.5");
  gStyle->SetOptStat(1111);
  
  jetZ360dPhiPbPbMC->SetLineColor(kRed);
  jetZ460dPhiPbPbMC->SetLineColor(TColor::GetColorDark(kGreen));
  jetZ560dPhiPbPbMC->SetLineColor(kBlue);

  stackdPhiPbPb60MC->Add(jetZ360dPhiPbPbMC, "sames");
  stackdPhiPbPb60MC->Add(jetZ460dPhiPbPbMC, "sames");
  stackdPhiPbPb60MC->Add(jetZ560dPhiPbPbMC, "sames");

  stackdPhiPbPb60MC->Draw("ehist nostack");

  dPhiPbPb60MC->Update();

  TPaveStats *statsdPhi360PbPbMC = (TPaveStats*)jetZ360dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi360PbPbMC->SetX1NDC(0.9); statsdPhi360PbPbMC->SetX2NDC(0.65);
  statsdPhi360PbPbMC->SetY1NDC(0.9); statsdPhi360PbPbMC->SetY2NDC(0.7);
  statsdPhi360PbPbMC->SetTextColor(kRed);

  dPhiPbPb60MC->Update();

  TPaveStats *statsdPhi460PbPbMC = (TPaveStats*)jetZ460dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi460PbPbMC->SetX1NDC(0.9); statsdPhi460PbPbMC->SetX2NDC(0.65);
  statsdPhi460PbPbMC->SetY1NDC(0.7); statsdPhi460PbPbMC->SetY2NDC(0.5);
  statsdPhi460PbPbMC->SetTextColor(TColor::GetColorDark(kGreen));

  dPhiPbPb60MC->Update();

  TPaveStats *statsdPhi560PbPbMC = (TPaveStats*)jetZ560dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi560PbPbMC->SetX1NDC(0.9); statsdPhi560PbPbMC->SetX2NDC(0.65);
  statsdPhi560PbPbMC->SetY1NDC(0.5); statsdPhi560PbPbMC->SetY2NDC(0.3);
  statsdPhi560PbPbMC->SetTextColor(kBlue);

  dPhiPbPb60MC->Update();

  stackdPhiPbPb60MC->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPbPb60MC->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPbPb60MC->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPbPb60MC->GetYaxis()->SetTitleOffset(1.5);

  dPhiPbPb60MC->Update();
  dPhiPbPb60MC->SaveAs("dPhiPbPb60MC.eps");
  dPhiPbPb60MC->Modified();

  TCanvas *dPhiPbPb100MC = new TCanvas;

  THStack *stackdPhiPbPb100MC = new THStack("stackdPhiPbPb100MC", "Z Pt>100GeV, Jet-Z azimuthal angle difference in heavy ion MC simulations");

  TH1F *jetZ3100dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet3100dPhiHisto");
  jetZ3100dPhiPbPbMC->SetName("R = 0.3");
  gStyle->SetOptStat(1111);

  TH1F *jetZ4100dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet4100dPhiHisto");
  jetZ4100dPhiPbPbMC->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  TH1F *jetZ5100dPhiPbPbMC = (TH1F*)PbPbMC->Get("demo/jet5100dPhiHisto");
  jetZ5100dPhiPbPbMC->SetName("R = 0.5");
  gStyle->SetOptStat(1111);

  jetZ3100dPhiPbPbMC->SetLineColor(kRed);
  jetZ4100dPhiPbPbMC->SetLineColor(TColor::GetColorDark(kGreen));
  jetZ5100dPhiPbPbMC->SetLineColor(kBlue);
  
  stackdPhiPbPb100MC->Add(jetZ3100dPhiPbPbMC, "sames");
  stackdPhiPbPb100MC->Add(jetZ4100dPhiPbPbMC, "sames");
  stackdPhiPbPb100MC->Add(jetZ5100dPhiPbPbMC, "sames");
  
  stackdPhiPbPb100MC->Draw("ehist nostack");
  
  dPhiPbPb100MC->Update();

  TPaveStats *statsdPhi3100PbPbMC = (TPaveStats*)jetZ3100dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi3100PbPbMC->SetX1NDC(0.9); statsdPhi3100PbPbMC->SetX2NDC(0.65);
  statsdPhi3100PbPbMC->SetY1NDC(0.9); statsdPhi3100PbPbMC->SetY2NDC(0.7);
  statsdPhi3100PbPbMC->SetTextColor(kRed);

  dPhiPbPb100MC->Update();

  TPaveStats *statsdPhi4100PbPbMC = (TPaveStats*)jetZ4100dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi4100PbPbMC->SetX1NDC(0.9); statsdPhi4100PbPbMC->SetX2NDC(0.65);
  statsdPhi4100PbPbMC->SetY1NDC(0.7); statsdPhi4100PbPbMC->SetY2NDC(0.5);
  statsdPhi4100PbPbMC->SetTextColor(TColor::GetColorDark(kGreen));

  dPhiPbPb100MC->Update();

  TPaveStats *statsdPhi5100PbPbMC = (TPaveStats*)jetZ5100dPhiPbPbMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi5100PbPbMC->SetX1NDC(0.9); statsdPhi5100PbPbMC->SetX2NDC(0.65);
  statsdPhi5100PbPbMC->SetY1NDC(0.5); statsdPhi5100PbPbMC->SetY2NDC(0.3);
  statsdPhi5100PbPbMC->SetTextColor(kBlue);

  dPhiPbPb100MC->Update();

  stackdPhiPbPb100MC->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPbPb100MC->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPbPb100MC->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPbPb100MC->GetYaxis()->SetTitleOffset(1.5);

  dPhiPbPb100MC->Update();
  dPhiPbPb100MC->SaveAs("dPhiPbPb100MC.eps");
  dPhiPbPb100MC->Modified();

  TCanvas *dPhiPbPb30Data = new TCanvas;

  THStack *stackdPhiPbPb30Data = new THStack("stackdPhiPbPb30Data", "Z Pt>30GeV, Jet-Z azimuthal angle difference in heavy ion collisions");

  TH1F *jetZ330dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet3dPhiHisto");
  jetZ330dPhiPbPbData->SetName("R = 0.3");  
  gStyle->SetOptStat(1111);

  TH1F *jetZ430dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet4dPhiHisto");
  jetZ430dPhiPbPbData->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  TH1F *jetZ530dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet5dPhiHisto");
  jetZ530dPhiPbPbData->SetName("R = 0.5");
  gStyle->SetOptStat(1111);

  jetZ330dPhiPbPbData->SetLineColor(kRed);
  jetZ430dPhiPbPbData->SetLineColor(TColor::GetColorDark(kGreen));
  jetZ530dPhiPbPbData->SetLineColor(kBlue);

  stackdPhiPbPb30Data->Add(jetZ330dPhiPbPbData, "sames");
  stackdPhiPbPb30Data->Add(jetZ430dPhiPbPbData, "sames");
  stackdPhiPbPb30Data->Add(jetZ530dPhiPbPbData, "sames");

  stackdPhiPbPb30Data->Draw("ehist nostack");

  dPhiPbPb30Data->Update();

  TPaveStats *statsdPhi330PbPbData = (TPaveStats*)jetZ330dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi330PbPbData->SetX1NDC(0.9); statsdPhi330PbPbData->SetX2NDC(0.65);
  statsdPhi330PbPbData->SetY1NDC(0.9); statsdPhi330PbPbData->SetY2NDC(0.7);
  statsdPhi330PbPbData->SetTextColor(kRed);

  dPhiPbPb30Data->Update();

  TPaveStats *statsdPhi430PbPbData = (TPaveStats*)jetZ430dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi430PbPbData->SetX1NDC(0.9); statsdPhi430PbPbData->SetX2NDC(0.65);
  statsdPhi430PbPbData->SetY1NDC(0.7); statsdPhi430PbPbData->SetY2NDC(0.5);
  statsdPhi430PbPbData->SetTextColor(TColor::GetColorDark(kGreen));

  dPhiPbPb30Data->Update();

  TPaveStats *statsdPhi530PbPbData = (TPaveStats*)jetZ530dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi530PbPbData->SetX1NDC(0.9); statsdPhi530PbPbData->SetX2NDC(0.65);
  statsdPhi530PbPbData->SetY1NDC(0.5); statsdPhi530PbPbData->SetY2NDC(0.3);
  statsdPhi530PbPbData->SetTextColor(kBlue);

  dPhiPbPb30Data->Update();

  stackdPhiPbPb30Data->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPbPb30Data->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPbPb30Data->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPbPb30Data->GetYaxis()->SetTitleOffset(1.5);

  dPhiPbPb30Data->Update();
  dPhiPbPb30Data->SaveAs("dPhiPbPb30Data.eps");
  dPhiPbPb30Data->Modified();

  TCanvas *dPhiPbPb60Data = new TCanvas;

  THStack *stackdPhiPbPb60Data = new THStack("stackdPhiPbPb60Data", "Z Pt>60GeV, Jet-Z azimuthal angle difference in heavy ion collisions");

  TH1F *jetZ360dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet360dPhiHisto");
  jetZ360dPhiPbPbData->SetName("R = 0.3");
  gStyle->SetOptStat(1111);

  TH1F *jetZ460dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet460dPhiHisto");
  jetZ460dPhiPbPbData->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  TH1F *jetZ560dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet560dPhiHisto");
  jetZ560dPhiPbPbData->SetName("R = 0.5");  
  gStyle->SetOptStat(1111);

  jetZ360dPhiPbPbData->SetLineColor(kRed);
  jetZ460dPhiPbPbData->SetLineColor(TColor::GetColorDark(kGreen));
  jetZ560dPhiPbPbData->SetLineColor(kBlue);

  stackdPhiPbPb60Data->Add(jetZ360dPhiPbPbData, "sames");
  stackdPhiPbPb60Data->Add(jetZ460dPhiPbPbData, "sames");
  stackdPhiPbPb60Data->Add(jetZ560dPhiPbPbData, "sames");

  stackdPhiPbPb60Data->Draw("ehist nostack");

  dPhiPbPb60Data->Update();

  TPaveStats *statsdPhi360PbPbData = (TPaveStats*)jetZ360dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi360PbPbData->SetX1NDC(0.9); statsdPhi360PbPbData->SetX2NDC(0.65);
  statsdPhi360PbPbData->SetY1NDC(0.9); statsdPhi360PbPbData->SetY2NDC(0.7);
  statsdPhi360PbPbData->SetTextColor(kRed);

  dPhiPbPb60Data->Update();

  TPaveStats *statsdPhi460PbPbData = (TPaveStats*)jetZ460dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi460PbPbData->SetX1NDC(0.9); statsdPhi460PbPbData->SetX2NDC(0.65);
  statsdPhi460PbPbData->SetY1NDC(0.7); statsdPhi460PbPbData->SetY2NDC(0.5);
  statsdPhi460PbPbData->SetTextColor(TColor::GetColorDark(kGreen));

  dPhiPbPb60Data->Update();

  TPaveStats *statsdPhi560PbPbData = (TPaveStats*)jetZ560dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi560PbPbData->SetX1NDC(0.9); statsdPhi560PbPbData->SetX2NDC(0.65);
  statsdPhi560PbPbData->SetY1NDC(0.5); statsdPhi560PbPbData->SetY2NDC(0.3);
  statsdPhi560PbPbData->SetTextColor(kBlue);

  dPhiPbPb60Data->Update();

  stackdPhiPbPb60Data->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPbPb60Data->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPbPb60Data->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPbPb60Data->GetYaxis()->SetTitleOffset(1.5);

  dPhiPbPb60Data->Update();
  dPhiPbPb60Data->SaveAs("dPhiPbPb60Data.eps");
  dPhiPbPb60Data->Modified();

  TCanvas *dPhiPbPb100Data = new TCanvas;

  THStack *stackdPhiPbPb100Data = new THStack("stackdPhiPbPb100Data", "Z Pt>100GeV, Jet-Z azimuthal angle difference in heavy ion collisions");

  TH1F *jetZ3100dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet3100dPhiHisto");
  jetZ3100dPhiPbPbData->SetName("R = 0.3");
  gStyle->SetOptStat(1111);

  TH1F *jetZ4100dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet4100dPhiHisto");
  jetZ4100dPhiPbPbData->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  TH1F *jetZ5100dPhiPbPbData = (TH1F*)PbPbData->Get("demo/jet5100dPhiHisto");
  jetZ5100dPhiPbPbData->SetName("R = 0.5");
  gStyle->SetOptStat(1111);

  jetZ3100dPhiPbPbData->SetLineColor(kRed);
  jetZ4100dPhiPbPbData->SetLineColor(TColor::GetColorDark(kGreen));
  jetZ5100dPhiPbPbData->SetLineColor(kBlue);

  stackdPhiPbPb100Data->Add(jetZ3100dPhiPbPbData, "sames");
  stackdPhiPbPb100Data->Add(jetZ4100dPhiPbPbData, "sames");
  stackdPhiPbPb100Data->Add(jetZ5100dPhiPbPbData, "sames");

  stackdPhiPbPb100Data->Draw("ehist nostack");

  dPhiPbPb100Data->Update();

  TPaveStats *statsdPhi3100PbPbData = (TPaveStats*)jetZ3100dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi3100PbPbData->SetX1NDC(0.9); statsdPhi3100PbPbData->SetX2NDC(0.65);
  statsdPhi3100PbPbData->SetY1NDC(0.9); statsdPhi3100PbPbData->SetY2NDC(0.7);
  statsdPhi3100PbPbData->SetTextColor(kRed);

  dPhiPbPb100Data->Update();

  TPaveStats *statsdPhi4100PbPbData = (TPaveStats*)jetZ4100dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi4100PbPbData->SetX1NDC(0.9); statsdPhi4100PbPbData->SetX2NDC(0.65);
  statsdPhi4100PbPbData->SetY1NDC(0.7); statsdPhi4100PbPbData->SetY2NDC(0.5);
  statsdPhi4100PbPbData->SetTextColor(TColor::GetColorDark(kGreen));

  dPhiPbPb100Data->Update();

  TPaveStats *statsdPhi5100PbPbData = (TPaveStats*)jetZ5100dPhiPbPbData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi5100PbPbData->SetX1NDC(0.9); statsdPhi5100PbPbData->SetX2NDC(0.65);
  statsdPhi5100PbPbData->SetY1NDC(0.5); statsdPhi5100PbPbData->SetY2NDC(0.3);
  statsdPhi5100PbPbData->SetTextColor(kBlue);

  dPhiPbPb100Data->Update();

  stackdPhiPbPb100Data->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPbPb100Data->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPbPb100Data->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPbPb100Data->GetYaxis()->SetTitleOffset(1.5);

  dPhiPbPb100Data->Update();
  dPhiPbPb100Data->SaveAs("dPhiPbPb100Data.eps");
  dPhiPbPb100Data->Modified();

  TCanvas *dPhiPP430MC = new TCanvas("dPhiPP", "Jet-Z azimuthal angle difference", 10,10,700,700);

  THStack *stackdPhiPP30MC = new THStack("stackdPhiPP30MC", "Z Pt>30GeV, Jet-Z azimuthal angle difference in proton-proton MC simulations");

  TH1F *jetZ430dPhiPPMC = (TH1F*)PPMC->Get("demo/jet4dPhiHisto");
  jetZ430dPhiPPMC->SetName("R = 0.4");  
  gStyle->SetOptStat(1111);

  stackdPhiPP30MC->Add(jetZ430dPhiPPMC, "sames");

  stackdPhiPP30MC->Draw("nostack");

  dPhiPP430MC->Update();

  TPaveStats *statsdPhi430PPMC = (TPaveStats*)jetZ430dPhiPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi430PPMC->SetX1NDC(0.9); statsdPhi430PPMC->SetX2NDC(0.65);
  statsdPhi430PPMC->SetY1NDC(0.9); statsdPhi430PPMC->SetY2NDC(0.7);

  dPhiPP430MC->Update();

  stackdPhiPP30MC->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPP30MC->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPP30MC->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPP30MC->GetYaxis()->SetTitleOffset(1.5);

  dPhiPP430MC->Update();
  dPhiPP430MC->SaveAs("dPhiPP430MC.eps");
  dPhiPP430MC->Modified();

  TCanvas *dPhiPP460MC = new TCanvas;
  
  THStack *stackdPhiPP60MC = new THStack("stackdPhiPP60MC", "Z Pt>60GeV, Jet-Z azimuthal angle difference in proton-proton MC simulations");

  TH1F *jetZ460dPhiPPMC = (TH1F*)PPMC->Get("demo/jet460dPhiHisto");
  jetZ460dPhiPPMC->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  stackdPhiPP60MC->Add(jetZ460dPhiPPMC, "sames");

  stackdPhiPP60MC->Draw("nostack");

  dPhiPP460MC->Update();

  TPaveStats *statsdPhi460PPMC = (TPaveStats*)jetZ460dPhiPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi460PPMC->SetX1NDC(0.9); statsdPhi460PPMC->SetX2NDC(0.65);
  statsdPhi460PPMC->SetY1NDC(0.9); statsdPhi460PPMC->SetY2NDC(0.7);

  dPhiPP460MC->Update();

  stackdPhiPP60MC->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPP60MC->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPP60MC->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPP60MC->GetYaxis()->SetTitleOffset(1.5);

  dPhiPP460MC->Update();
  dPhiPP460MC->SaveAs("dPhiPP460MC.eps");
  dPhiPP460MC->Modified();

  TCanvas *dPhiPP4100MC = new TCanvas;

  THStack *stackdPhiPP100MC = new THStack("stackdPhiPP100MC", "Z Pt>100GeV, Jet-Z azimuthal angle difference in proton-proton MC simulations");
  
  TH1F *jetZ4100dPhiPPMC = (TH1F*)PPMC->Get("demo/jet4100dPhiHisto");
  jetZ4100dPhiPPMC->SetName("R = 0.4");
  gStyle->SetOptStat(1111);
  
  stackdPhiPP100MC->Add(jetZ4100dPhiPPMC, "sames");

  stackdPhiPP100MC->Draw("nostack");

  dPhiPP4100MC->Update();

  TPaveStats *statsdPhi4100PPMC = (TPaveStats*)jetZ4100dPhiPPMC->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi4100PPMC->SetX1NDC(0.9); statsdPhi4100PPMC->SetX2NDC(0.65);
  statsdPhi4100PPMC->SetY1NDC(0.9); statsdPhi4100PPMC->SetY2NDC(0.7);

  dPhiPP4100MC->Update();

  stackdPhiPP100MC->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPP100MC->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPP100MC->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPP100MC->GetYaxis()->SetTitleOffset(1.5);

  dPhiPP4100MC->Update();
  dPhiPP4100MC->SaveAs("dPhiPP4100MC.eps");
  dPhiPP4100MC->Modified();

  TCanvas *dPhiPP430Data = new TCanvas;

  THStack *stackdPhiPP30Data = new THStack("stackdPhiPP30Data", "Z Pt>30GeV, Jet-Z azimuthal angle difference in proton-proton collisions");

  TH1F *jetZ430dPhiPPData = (TH1F*)PPData->Get("demo/jet4dPhiHisto");
  jetZ430dPhiPPData->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  stackdPhiPP30Data->Add(jetZ430dPhiPPData, "sames");

  stackdPhiPP30Data->Draw("nostack");

  dPhiPP430Data->Update();

  TPaveStats *statsdPhi430PPData = (TPaveStats*)jetZ430dPhiPPData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi430PPData->SetX1NDC(0.9); statsdPhi430PPData->SetX2NDC(0.65);
  statsdPhi430PPData->SetY1NDC(0.9); statsdPhi430PPData->SetY2NDC(0.7);

  dPhiPP430Data->Update();

  stackdPhiPP30Data->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPP30Data->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPP30Data->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPP30Data->GetYaxis()->SetTitleOffset(1.5);

  dPhiPP430Data->Update();
  dPhiPP430Data->SaveAs("dPhiPP430Data.eps");
  dPhiPP430Data->Modified();

  TCanvas *dPhiPP460Data = new TCanvas;

  THStack *stackdPhiPP60Data = new THStack("stackdPhiPP60Data", "Z Pt>60GeV, Jet-Z azimuthal angle difference in proton-proton collisions");

  TH1F *jetZ460dPhiPPData = (TH1F*)PPData->Get("demo/jet460dPhiHisto");
  jetZ460dPhiPPData->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  stackdPhiPP60Data->Add(jetZ460dPhiPPData, "sames");

  stackdPhiPP60Data->Draw("nostack");

  dPhiPP460Data->Update();

  TPaveStats *statsdPhi460PPData = (TPaveStats*)jetZ460dPhiPPData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi460PPData->SetX1NDC(0.9); statsdPhi460PPData->SetX2NDC(0.65);
  statsdPhi460PPData->SetY1NDC(0.9); statsdPhi460PPData->SetY2NDC(0.7);

  dPhiPP460Data->Update();
  
  stackdPhiPP60Data->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPP60Data->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPP60Data->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPP60Data->GetYaxis()->SetTitleOffset(1.5);
 
  dPhiPP460Data->Update();
  dPhiPP460Data->SaveAs("dPhiPP460Data.eps");
  dPhiPP460Data->Modified();

  TCanvas *dPhiPP4100Data = new TCanvas;

  THStack *stackdPhiPP100Data = new THStack("stackdPhiPP100Data", "Z Pt>100GeV, Jet-Z azimuthal angle difference in proton-proton collisions");

  TH1F *jetZ4100dPhiPPData = (TH1F*)PPData->Get("demo/jet4100dPhiHisto");
  jetZ4100dPhiPPData->SetName("R = 0.4");
  gStyle->SetOptStat(1111);

  stackdPhiPP100Data->Add(jetZ4100dPhiPPData, "sames");

  stackdPhiPP100Data->Draw("nostack");

  dPhiPP4100Data->Update();

  TPaveStats *statsdPhi4100PPData = (TPaveStats*)jetZ4100dPhiPPData->GetListOfFunctions()->FindObject("stats"); 
  statsdPhi4100PPData->SetX1NDC(0.9); statsdPhi4100PPData->SetX2NDC(0.65);
  statsdPhi4100PPData->SetY1NDC(0.9); statsdPhi4100PPData->SetY2NDC(0.7);

  dPhiPP4100Data->Update();
  
  stackdPhiPP100Data->GetXaxis()->SetTitle("Azimuthal angle, dPhi, between the jets and Z boson candidates, (rad)");
  stackdPhiPP100Data->GetXaxis()->SetTitleOffset(1.5);
  stackdPhiPP100Data->GetYaxis()->SetTitle("Number of back-to-back Jet-Z events");
  stackdPhiPP100Data->GetYaxis()->SetTitleOffset(1.5);
  
  dPhiPP4100Data->Update();
  dPhiPP4100Data->SaveAs("dPhiPP4100Data.eps");
  dPhiPP4100Data->Modified();

}
