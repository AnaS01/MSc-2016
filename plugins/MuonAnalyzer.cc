// -*- C++ -*-
//
// Package:    FirstAnalyzer/MuonAnalyzer
// Class:      MuonAnalyzer
// 
/**\class MuonAnalyzer MuonAnalyzer.cc FirstAnalyzer/MuonAnalyzer/plugins/MuonAnalyzer.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  Ana Snjegota
//         Created:  Mon, 19 Sep 2016 08:38:16 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <DataFormats/MuonReco/interface/Muon.h>
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"
#include "TH3.h"
#include <math.h>
# define M_PI 3.14159265358979323846 

struct Jet
{
    float pt = 0.0f;
    float phi = 0.0f;
    float eta = 0.0f;
    float theta = 0.0f;
    float dPhi = 0.0f;
};

struct ZCandidate
{
    float mass = 0.0f;
    float pt = 0.0f;
    float p = 0.0f;
    float phi = 0.0f;
    float eta = 0.0f;
    float theta = 0.0f;
    reco::Candidate::Point vertex;
};

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class MuonAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
    explicit MuonAnalyzer(const edm::ParameterSet&);
    ~MuonAnalyzer();

    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


private:
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

// ----------member data ---------------------------
    TH1D *goodMuonsPerEventHisto;
    TH1D *zCandidatesHisto;

    TH1F *motherInvMassHisto;
    TH1F *motherPtHisto;
    TH1F *motherPHisto;
    TH1F *motherPhiHisto;
    TH1F *motherEtaHisto;
    TH1F *motherThetaHisto;

    TH3F *motherVertexHisto;
    TH3F *primaryVertexHisto;

    TH1F *akVs3PFJetPtHisto;
    TH1F *akVs4PFJetPtHisto;
    TH1F *akVs5PFJetPtHisto;

    TH1F *jet3PhiHisto;
    TH1F *jet4PhiHisto;
    TH1F *jet5PhiHisto;

    TH1F *jet3EtaHisto;
    TH1F *jet4EtaHisto;
    TH1F *jet5EtaHisto;

    TH1F *jet3ThetaHisto;
    TH1F *jet4ThetaHisto;
    TH1F *jet5ThetaHisto;

    TH1F *jet3Z30PtRatioHisto;
    TH1F *jet4Z30PtRatioHisto;
    TH1F *jet5Z30PtRatioHisto;

    TH1F *jet330dPhiHisto;
    TH1F *jet430dPhiHisto;
    TH1F *jet530dPhiHisto;

	TH1F *jet3Z60PtRatioHisto;
	TH1F *jet4Z60PtRatioHisto;
	TH1F *jet5Z60PtRatioHisto;

	TH1F *jet360dPhiHisto;
	TH1F *jet460dPhiHisto;
	TH1F *jet560dPhiHisto;

	TH1F *jet3Z100PtRatioHisto;
	TH1F *jet4Z100PtRatioHisto;
	TH1F *jet5Z100PtRatioHisto;

	TH1F *jet3100dPhiHisto;
	TH1F *jet4100dPhiHisto;
	TH1F *jet5100dPhiHisto;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MuonAnalyzer::MuonAnalyzer(const edm::ParameterSet& iConfig)

{
//now do what ever initialization is needed
    usesResource("TFileService");
    edm::Service<TFileService> fs;

    goodMuonsPerEventHisto=fs->make<TH1D>("goodMuonsPerEvent" , "Good muons in each event" , 10,0,10); 
    zCandidatesHisto=fs->make<TH1D>("candidates" , "Candidates" , 10,0,10);

    motherInvMassHisto=fs->make<TH1F>("motherInvMass" , "Mother Mass" , 200,70,110); 
    motherPtHisto=fs->make<TH1F>("motherPt" , "Mother Pt" , 200,0,1000); 
    motherPHisto=fs->make<TH1F>("motherP" , "Mother P" , 200,0,1000);
    motherPhiHisto=fs->make<TH1F>("motherPhi" , "Mother Phi" , 200,-3.5, 3.5);
    motherEtaHisto=fs->make<TH1F>("motherEta" , "Mother Eta" , 200, -10, 10);
    motherThetaHisto=fs->make<TH1F>("motherTheta" , "Mother Theta" , 200, -0.5, 3.5);

    motherVertexHisto=fs->make<TH3F>("motherVertex" , "Mother Vertex" , 200,-0.1,0.1, 200,-0.1,0.1,200,-20,20);
    motherVertexHisto->SetXTitle("x");
    motherVertexHisto->SetYTitle("y");
    motherVertexHisto->SetZTitle("z");

    primaryVertexHisto=fs->make<TH3F>("primaryVertex" , "Primary Vertex" , 200,-0.1,0.1, 200,-0.1,0.1,200,-20,20);
    primaryVertexHisto->SetXTitle("x");
    primaryVertexHisto->SetYTitle("y");
    primaryVertexHisto->SetZTitle("z");

    akVs3PFJetPtHisto=fs->make<TH1F>("akVs3PFJetPt" , "ak R=0.3 Jet Pt" , 200,0,200);
    akVs4PFJetPtHisto=fs->make<TH1F>("akVs4PFJetPt" , "ak R=0.4 Jet Pt" , 200,0,200);
    akVs5PFJetPtHisto=fs->make<TH1F>("akVs5PFJetPt" , "ak R=0.5 Jet Pt" , 200,0,200);

    jet3PhiHisto=fs->make<TH1F>("jet3PhiHisto" , "R=0.3 Jet Phi" , 200, -3.5,3.5);
    jet4PhiHisto=fs->make<TH1F>("jet4PhiHisto" , "R=0.4 Jet Phi" , 200, -3.5,3.5);
    jet5PhiHisto=fs->make<TH1F>("jet5PhiHisto" , "R=0.5 Jet Phi" , 200, -3.5,3.5);

    jet3EtaHisto=fs->make<TH1F>("jet3EtaHisto" , "R=0.3 Jet Eta" , 200, -2,2);
    jet4EtaHisto=fs->make<TH1F>("jet4EtaHisto" , "R=0.4 Jet Eta" , 200, -2,2);
    jet5EtaHisto=fs->make<TH1F>("jet5EtaHisto" , "R=0.5 Jet Eta" , 200, -2,2);

    jet3ThetaHisto=fs->make<TH1F>("jet3ThetaHisto" , "R=0.3 Jet Theta" , 200, -0.5,3.5);
    jet4ThetaHisto=fs->make<TH1F>("jet4ThetaHisto" , "R=0.4 Jet Theta" , 200, -0.5,3.5);
    jet5ThetaHisto=fs->make<TH1F>("jet5ThetaHisto" , "R=0.5 Jet Theta" , 200, -0.5,3.5);
   
    jet3Z30PtRatioHisto=fs->make<TH1F>("jet3Z30Ratio" , "Z Pt>30, R=0.3 Jet-Z Pt Ratio" , 200,0,4);
    jet4Z30PtRatioHisto=fs->make<TH1F>("jet4Z30Ratio" , "Z Pt>30, R=0.4 Jet-Z Pt Ratio" , 200,0,4);
    jet5Z30PtRatioHisto=fs->make<TH1F>("jet5Z30Ratio" , "Z Pt>30, R=0.5 Jet-Z Pt Ratio" , 200,0,4);

    jet330dPhiHisto=fs->make<TH1F>("jet3dPhiHisto" , "Z Pt>30, R=0.3 dPhi" , 200, 2.5,3.5);
    jet430dPhiHisto=fs->make<TH1F>("jet4dPhiHisto" , "Z Pt>30, R=0.4 dPhi" , 200, 2.5,3.5);
    jet530dPhiHisto=fs->make<TH1F>("jet5dPhiHisto" , "Z Pt>30, R=0.5 dPhi" , 200, 2.5,3.5);

	jet3Z60PtRatioHisto = fs->make<TH1F>("jet3Z60Ratio", "Z Pt>60, R=0.3 Jet-Z Pt Ratio", 200, 0, 4);
	jet4Z60PtRatioHisto = fs->make<TH1F>("jet4Z60Ratio", "Z Pt>60, R=0.4 Jet-Z Pt Ratio", 200, 0, 4);
	jet5Z60PtRatioHisto = fs->make<TH1F>("jet5Z60Ratio", "Z Pt>60, R=0.5 Jet-Z Pt Ratio", 200, 0, 4);

	jet360dPhiHisto = fs->make<TH1F>("jet360dPhiHisto", "Z Pt>60, R=0.3 dPhi", 200, 2.5, 3.5);
	jet460dPhiHisto = fs->make<TH1F>("jet460dPhiHisto", "Z Pt>60, R=0.4 dPhi", 200, 2.5, 3.5);
	jet560dPhiHisto = fs->make<TH1F>("jet560dPhiHisto", "Z Pt>60, R=0.5 dPhi", 200, 2.5, 3.5);

	jet3Z100PtRatioHisto = fs->make<TH1F>("jet3Z100Ratio", "Z Pt>100, R=0.3 Jet-Z Pt Ratio", 200, 0, 4);
	jet4Z100PtRatioHisto = fs->make<TH1F>("jet4Z100Ratio", "Z Pt>100, R=0.4 Jet-Z Pt Ratio", 200, 0, 4);
	jet5Z100PtRatioHisto = fs->make<TH1F>("jet5Z100Ratio", "Z Pt>100, R=0.5 Jet-Z Pt Ratio", 200, 0, 4);

	jet3100dPhiHisto = fs->make<TH1F>("jet3100dPhiHisto", "Z Pt>100, R=0.3 dPhi", 200, 2.5, 3.5);
	jet4100dPhiHisto = fs->make<TH1F>("jet4100dPhiHisto", "Z Pt>100, R=0.4 dPhi", 200, 2.5, 3.5);
	jet5100dPhiHisto = fs->make<TH1F>("jet5100dPhiHisto", "Z Pt>100, R=0.5 dPhi", 200, 2.5, 3.5);
}


MuonAnalyzer::~MuonAnalyzer()
{

// do anything here that needs to be done at desctruction time
// (e.g. close files, deallocate resources etc.)

}


//
// member functions
//
float CalcEta(const reco::Muon& m1, const reco::Muon& m2)
{
    float motherTheta = 0.0f;
    double px1 = m1.px();
    double px2 = m2.px();
    double py1 = m1.py();
    double py2 = m2.py();
    double pz1 = m1.pz();
    double pz2 = m2.pz();

    if (pz1 + pz2 == 0.0) //to avoid division by 0 later
        return 9999;

    motherTheta = atan(sqrt(pow((px1 + px2),2) + pow((py1 + py2),2))/(pz1 + pz2));

    if (motherTheta == M_PI || motherTheta  == 0.0f) //to avoid log(infinity) or log(0) later 
        return 9999;

    if(pz1 + pz2 < 0.0)
    {
        //if the z candidate is going backwards along the beam line (-z direction), the angle we need is PI - theta, but since theta is negative already
        //the calculation is PI + theta

        motherTheta = M_PI + motherTheta;
    }

    //returns the pseudorapidity, eta, of mother particle

    return -log(tan(motherTheta/2.0f));
}

float CalcPhi(const reco::Muon& m1, const reco::Muon& m2)
{
    float motherPhi = 0.0f;
    double px1 = m1.px();
    double px2 = m2.px();
    double py1 = m1.py();
    double py2 = m2.py();

    //returns the azimuthal angle, phi, of mother particle

    //the calculation for phi is the same for the 1st and 4th quadrants
    motherPhi = atan((py1 + py2)/(px1 + px2));

    if (px1 + px2 < 0)
    {
        if (py1 + py2 > 0)
            //atan(y/-x) = -atan(y/x) therefore the angle we need is PI - (-atan(y/x) = PI + atan(y/x)
            motherPhi = M_PI + motherPhi; 
        else 
            //the range in -y goes from 0 to -PI. The angle we need is -PI + atan(-y/-x) = -PI + atan(y/x)
            motherPhi = -M_PI + motherPhi;
    }

    return motherPhi;
}

float CalcP(const reco::Muon &m1, const reco::Muon &m2)
{
    //returns the total momentum, p, of mother particle 
    return sqrt((pow((m1.px() + m2.px()), 2) + pow((m1.py() + m2.py()), 2) + pow((m1.pz() + m2.pz()), 2)));
}

float CalcPt(const reco::Muon& m1, const reco::Muon& m2)
{
    //returns transverse momentum, pt, of mother particle
    return sqrt((pow((m1.px() + m2.px()) , 2) + pow((m1.py() + m2.py()) , 2)));
}

float CalcMass(const reco::Muon& m1, const reco::Muon& m2)
{  
    double motherPTemp = sqrt((pow((m1.px() + m2.px()), 2) + pow((m1.py() + m2.py()), 2) + pow((m1.pz() + m2.pz()), 2)));
    double motherETemp = m1.energy() + m2.energy();

    //returns invariant mass, m, of mother particle
    return sqrt((pow(motherETemp , 2) - pow(motherPTemp , 2)));
}

float ThetaFromEta(float eta)
{
    return 2.0f * atan(exp(-eta));
}

bool TestJet(const std::vector<reco::PFJet>& jets, ZCandidate* zc, Jet& retJet)
{
    bool jetFound = false;
    for (uint i = 0; i < jets.size(); i++)
    {
        const reco::PFJet& jet = jets.at(i);

        if (fabs(jet.eta()) > 1.6)
            continue;

        if (jet.pt() < 30)
            continue; 

        // Check if jet direction is roughly opposite z candidate's direction  
        float dPhi = fabs(zc->phi - jet.phi());

	//if the phi angle difference between jet and z is greater than PI then take the inner angle (opposite)
        if(dPhi > M_PI)
            dPhi = 2.0f * M_PI - dPhi;

	//azimuthal angle between jet and z has to be at least 7/8PI
	if (dPhi < 7.0f/8.0f*M_PI) 
	  continue;

	if(!jetFound || (retJet.dPhi < dPhi))
        {
            retJet.pt = jet.pt();
            retJet.phi = jet.phi();
            retJet.eta = jet.eta();
	    retJet.theta = ThetaFromEta(jet.eta());
	    retJet.dPhi = dPhi;

            jetFound = true;
        }
    }
    return jetFound;
}

// ------------ method called for each event  ------------
void MuonAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    LogInfo("MainLoop") << "Call to analyze()";

    Handle<std::vector<reco::Muon>> muons;
    Handle<std::vector<reco::PFJet>>jets3;
    Handle<std::vector<reco::PFJet>>jets4;
    Handle<std::vector<reco::PFJet>>jets5; 
    Handle<std::vector<reco::Vertex>>vertices; 

    iEvent.getByLabel("muons", muons);
    //Use this for PP
    iEvent.getByLabel("ak4PFJets" , jets4);
    //Use this for PbPb
    //iEvent.getByLabel("akVs3PFJets" , jets3);
    //iEvent.getByLabel("akVs4PFJets" , jets4);
    //iEvent.getByLabel("akVs5PFJets" , jets5);
    //Use this for PP
    iEvent.getByLabel("offlinePrimaryVerticesWithBS" , vertices);
    // Use this for PbPb 
    //iEvent.getByLabel("hiSelectedVertex" , vertices);

    reco::Vertex primaryVertex = vertices->at(0);

    LogInfo("MainLoop") << "Muons size: " << muons->size();

    if (muons->size()<2)
        return;

    std::vector<ZCandidate*> zCandidates;
    int muonIndices[10];
    int muonCount = 0;

    for (uint n=0; n<muons->size();n++) {

        const reco::Muon& m = muons->at(n);

        if(m.pt() < 15)
            continue;

        if(fabs(m.eta()) > 2.4)
            continue;

        if(!m.isGlobalMuon() && !m.isTrackerMuon())
            continue;

        if(m.numberOfMatchedStations() <= 1)
            continue;

	//Z distance must be less than 0.5cm
        if(fabs(m.vz() - primaryVertex.z()) > 0.5)
            continue;

        // X-Y distance must be less than 0.2mm (0.02cm)  
        if((pow(m.vx() - primaryVertex.x(), 2) + pow(m.vy() - primaryVertex.y(), 2)) > 0.0004)
            continue;

        reco::TrackRef track =  m.globalTrack();

        if (track.isNull())
            continue;

        if(track->normalizedChi2() >= 10)
            continue;

	if(track->hitPattern().numberOfValidMuonHits() == 0)
	  continue;

	reco::TrackRef innerTrack = m.innerTrack();
	
	if(innerTrack.isNull())
	  continue;

	if(innerTrack->hitPattern().numberOfValidTrackerHits() <= 10)
	  continue;

	if(innerTrack->hitPattern().numberOfValidPixelHits() == 0)
	  continue;

        if(muonCount == 9)
        {
            LogError("MainLoop") << "*** OVERFLOW ***";
            break;
        }

        muonIndices[muonCount++] = n;
    }

    LogInfo("MainLoop") << "Muons passed: " << muonCount;
    goodMuonsPerEventHisto->Fill(muonCount);

    for(int i = 0; i < muonCount -1; i++)
    {
        for(int j = i + 1; j < muonCount; j++)
        {
            const reco::Muon& m1 = muons->at(muonIndices[i]);
            const reco::Muon& m2 = muons->at(muonIndices[j]);

            if(m1.charge() * m2.charge() > 0)
                continue;

            if(fabs(m1.vz() - m2.vz()) > 0.5)
                continue;

            // X-Y distance must be less than 0.2mm (0.02cm)  
            if((pow(m1.vx() - m2.vx(), 2) + pow(m1.vy() - m2.vy(), 2)) > 0.0004)
                continue;

            float zMass = CalcMass(m1,m2);

            if(zMass > 70.0f && zMass < 110.0f)
            {
	        motherInvMassHisto->Fill(zMass);

		//Doing a Gaussian fit shows that only masses 82-99GeV are relevant to the analysis

		if(zMass > 82.0f && zMass < 99.0f)
		  {
		    ZCandidate* z = new ZCandidate();
		    z->mass = zMass;
		    z->pt = CalcPt(m1,m2);
		    z->p = CalcP(m1,m2);
		    z->phi = CalcPhi(m1,m2);
		    z->eta = CalcEta(m1,m2);
		    z->theta = ThetaFromEta(z->eta);
		    z->vertex = m1.vertex();
		    
		    zCandidates.push_back(z);
		    
		    motherPtHisto->Fill(z->pt);
		    motherPHisto->Fill(z->p);
		    motherPhiHisto->Fill(z->phi);
		    motherEtaHisto->Fill(z->eta);
		    motherThetaHisto->Fill(z->theta);
		    
		    motherVertexHisto->Fill(z->vertex.x(), z->vertex.y(), z->vertex.z());
		    primaryVertexHisto->Fill(primaryVertex.x(), primaryVertex.y(), primaryVertex.z());
		  }
	    }
        }
    }

    zCandidatesHisto->Fill(zCandidates.size());
    LogInfo("MainLoop") << "ZCandidates: " << zCandidates.size();

    for(uint j = 0; j < zCandidates.size(); j++)
    {
        ZCandidate* zc = zCandidates.at(j);
        if (zc->pt < 30)
            continue;

		Jet jet;

		//Use for PbPb
		/*if (TestJet(*jets3, zc, jet))
		  {
			jet3Z30PtRatioHisto->Fill(jet.pt / zc->pt);
			akVs3PFJetPtHisto->Fill(jet.pt);
			jet3PhiHisto->Fill(jet.phi);
			jet3EtaHisto->Fill(jet.eta);
			jet3ThetaHisto->Fill(jet.theta);
			jet330dPhiHisto->Fill(jet.dPhi);

			if (zc->pt > 60)
			{
			jet3Z60PtRatioHisto->Fill(jet.pt / zc->pt);
			jet360dPhiHisto->Fill(jet.dPhi);
			}

			if (zc->pt > 100)
			{
			jet3Z100PtRatioHisto->Fill(jet.pt / zc->pt);
			jet3100dPhiHisto->Fill(jet.dPhi);
			}
			
			}*/

		if (TestJet(*jets4, zc, jet))
		{
			jet4Z30PtRatioHisto->Fill(jet.pt / zc->pt);
			akVs4PFJetPtHisto->Fill(jet.pt);
			jet4PhiHisto->Fill(jet.phi);
			jet4EtaHisto->Fill(jet.eta);
			jet4ThetaHisto->Fill(jet.theta);
			jet430dPhiHisto->Fill(jet.dPhi);

			if (zc->pt > 60)
			{
				jet4Z60PtRatioHisto->Fill(jet.pt / zc->pt);
				jet460dPhiHisto->Fill(jet.dPhi);
			}

			if (zc->pt > 100)
			{
				jet4Z100PtRatioHisto->Fill(jet.pt / zc->pt);
				jet4100dPhiHisto->Fill(jet.dPhi);
			}
			
		}

		//Use for PbPb
		/*if (TestJet(*jets5, zc, jet))
		  {	
			jet5Z30PtRatioHisto->Fill(jet.pt / zc->pt);
			akVs5PFJetPtHisto->Fill(jet.pt);
			jet5PhiHisto->Fill(jet.phi);
			jet5EtaHisto->Fill(jet.eta);
			jet5ThetaHisto->Fill(jet.theta);
			jet530dPhiHisto->Fill(jet.dPhi);

			if (zc->pt > 60)
			{
			jet5Z60PtRatioHisto->Fill(jet.pt / zc->pt);
			jet560dPhiHisto->Fill(jet.dPhi);
			}

			if (zc->pt > 100)
			{
			jet5Z100PtRatioHisto->Fill(jet.pt / zc->pt);
			jet5100dPhiHisto->Fill(jet.dPhi);
			}	

			}*/

		
		
		// Delete allocated objects to avoid memory leaks
		delete zc;
    }
}



// ------------ method called once each job just before starting event loop  ------------
void 
MuonAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
MuonAnalyzer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MuonAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
//The following says we do not know what parameters are allowed so do no validation
// Please change this to state exactly what you do use, even if it is no parameters
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MuonAnalyzer);
