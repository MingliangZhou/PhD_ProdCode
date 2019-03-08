/*************************************************************************
  > File Name: tree.C
 ************************************************************************/
#include<iostream>
#include<Riostream.h>
#include<TTree.h>
#include<TFile.h>
#include<fstream>
using namespace std;

void tree(Int_t total = 1, Int_t seed=0) {

    const Int_t kMaxTrack = 50000;

    Int_t   ieve;
    Int_t   jeve;
    Int_t   ntrk;
    Int_t   nqrk;
    Float_t bimp;
    Int_t   eid[6];
    Int_t   id[kMaxTrack];
    Float_t px[kMaxTrack];
    Float_t py[kMaxTrack];
    Float_t pz[kMaxTrack];
    Float_t ms[kMaxTrack];
    Float_t x[kMaxTrack];
    Float_t y[kMaxTrack];
    Float_t z[kMaxTrack];
    Float_t t[kMaxTrack];
    Float_t qx[kMaxTrack];
    Float_t qy[kMaxTrack];
    Float_t qz[kMaxTrack];

    TFile f("ampt.root","recreate");

    TTree *seed_tr=new TTree("seed","seed");
    Int_t iseed;
    seed_tr->Branch("Rdm_seed",&iseed,"Rdm_seed/I");
    iseed=seed;
    seed_tr->Fill();

    TTree *tt = new TTree("tt","AMPT tree");
    tt->Branch("ieve",&ieve,"ieve/I");
    tt->Branch("jeve",&jeve,"jeve/I");
    tt->Branch("ntrk",&ntrk,"ntrk/I");
    tt->Branch("nqrk",&nqrk,"nqrk/I");
    tt->Branch("bimp",&bimp,"bimp/F");
    tt->Branch("eid",eid,"eid[6]/I");
    tt->Branch("id",id,"id[ntrk]/I");
    tt->Branch("px",px,"px[ntrk]/F");
    tt->Branch("py",py,"py[ntrk]/F");
    tt->Branch("pz",pz,"pz[ntrk]/F");
    tt->Branch("ms",ms,"ms[ntrk]/F");
    tt->Branch("x",x,"x[ntrk]/F");
    tt->Branch("y",y,"y[ntrk]/F");
    tt->Branch("z",z,"z[ntrk]/F");
    tt->Branch("t",t,"t[ntrk]/F");
    tt->Branch("qx",qx,"qx[nqrk]/F");
    tt->Branch("qy",qy,"qy[nqrk]/F");
    tt->Branch("qz",qz,"qz[nqrk]/F");

    Int_t   npart,id_part[1000],st_part[1000];
    Float_t x_part[1000],y_part[1000];
    tt->Branch("npart"  ,&npart ,"npart/I");
    tt->Branch("x_part" ,x_part ,"x_part[npart]/F");
    tt->Branch("y_part" ,y_part ,"y_part[npart]/F");
    tt->Branch("id_part",id_part,"id_part[npart]/I");
    tt->Branch("st_part",st_part,"st_part[npart]/I");

    ifstream ifs;   ifs.open("ampt.dat");
    ifstream jfs;   jfs.open("zpc.dat");
    ifstream nfs;   nfs.open("npart-xy.dat");

    Int_t   i0,i1,i2,i3,i4,i5;
    Float_t f0,f1,f2,f3,f4,f5,f6,f7;

    for (Int_t i=0; i<total; i++) {
        ifs >> ieve >> jeve >> ntrk >> bimp >> i0 >> i1 >> i2 >> i3 >> i4 >> i5;
        eid[0]=i0;
        eid[1]=i1;
        eid[2]=i2;
        eid[3]=i3;
        eid[4]=i4;
        eid[5]=i5;
        for (Int_t n=0; n<ntrk; n++) {
            ifs >> i0 >> f0 >> f1 >> f2 >> f3 >> f4 >> f5 >> f6 >> f7;
            id[n] = i0;
            px[n] = f0;
            py[n] = f1;
            pz[n] = f2;
            ms[n] = f3;
            x[n]  = f4;
            y[n]  = f5;
            z[n]  = f6;
            t[n]  = f7;
        }
        jfs >> i0 >> nqrk >> f0 >> i1 >> i2 >> i3 >> i4;
        for (Int_t n=0; n<nqrk; n++) {
            jfs >> f0 >> f1 >> f2 >> i0 >> f3 >> f4 >> i1 >> i2 >> f5;
            qx[n] = f0;
            qy[n] = f1;
            qz[n] = f2;
        }
        cout << i << " " << ieve << " " << jeve << " " << ntrk << " " << nqrk << " " << bimp << endl;
        nfs >> i0 >> i1 >> i2 >> i3; 
        npart=i2+i3;
        for (Int_t n=0; n<npart; n++) {
            nfs >> f0 >> f1 >> i0 >> i1;
            x_part[n]=f0;
            y_part[n]=f1;
            id_part[n]=i0;
            st_part[n]=i1;
        }
        cout<<"npart == "<<npart<<endl;
        tt->Fill();
    }
    ifs.close();
    jfs.close();
    nfs.close();
    tt->Print();
    tt->Write();
    seed_tr->Write(); 
    f.Close();
}
