#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoop/LSFDriver.h"
#include <string>


#include "checkTrack/MyxAODAnalysis.h"
//#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoop/OutputStream.h>

#include <unistd.h>


void usage() {
  std::cout << "Usage: runTrackEfficiency [options] inputDirectory outputDirectory\n"
            << "Options:\n"
            << "  -f, readFileList        read input files from a *.txt file\n"
            << "                          (in this case 'inputDirectory' is the *.txt file)\n"
            << "  -n, nEvents             number of events to run\n"
          //  << "  -w, weight              weighting level: 0 no weighting - 1 Z weighting - 2 eta-pT weighting\n"
          //  << "  -q, filename of weight  filename including the weights\n"
          //  << "  -x, vertex              disable vertex\n"
          //  << "  -t, trigger             disable trigger\n"
          //  << "  -g, grl                 disable GRL\n"
            << "  -u, grid nickname       run on grid\n"
            << "  -v, version             output file version for grid\n"
            << "  -b, batch               split the jobs into parts and run on lxbatch\n"
          //  << "  -p, performance plots   create performance plots and disable most detailed histograms\n"
          //  << "  -z, singleParticles     use weights for single particles\n"
            << std::endl;
}

int main( int argc, char* argv[] ) {

    int c;
    bool local = true;
    bool batch = false;
    bool readFileList = false;
    //unsigned int weight = 0;
    //std::string weightFile = ""; // Need to change this
    //bool GRL = true;
    //bool trigger = true;
    //bool vertex = true;
    std::string username = "";
    std::string version = "";
    std::string fileList = "";
    int nEvents = -1;
    //int skipEvents = 0;
    //bool performance = false;
    //bool singleParticles = false;

    while( (c = getopt (argc, argv, "bu:v:fn:s:w:q:gtpzx")) != -1 ) {
        switch( c ) {
            case 'b':
                local = false;
                batch = true;
                break;
            case 'u':
                local = false;
                batch = false;
                username = optarg;
                break;
            case 'v':
                version = optarg;
                break;
            case 'f':
                readFileList = true;
                break;
            case 'n':
                nEvents = atoi(optarg);
                break;
                /*
                   case 's':
                   skipEvents = atoi(optarg);
                   break;

                   case 'w':
                   weight = atoi(optarg);
                   break;
                   case 'q':
                   weightFile = optarg;
                   break;
                   case 'g':
                   GRL = false;
                   break;
                   case 't':
                   trigger = false;
                   break;
                   case 'p':
                   performance = true;
                   break;
                   case 'x':
                   vertex = false;
                   break;
                   case 'z':
                   singleParticles = true;
                   break;
                   */
            case '?':
                usage();
                return 1;
            default:
                abort();
        }
    }

    if (argc - optind < 2) {
        usage();
        return 1;
    }
    std::cout<<argc<<" argc optind "<<optind<<std::endl;
    std::string inputDir = argv[optind++];
    std::string outputDir = argv[optind++];
    std::cout<<inputDir<<std::endl;
    std::cout<<outputDir<<std::endl;

    // Set up the job for xAOD access:
    xAOD::Init().ignore();

    // Construct the samples to run on:
    SH::SampleHandler sh;
    if( readFileList ) {
        SH::readFileList (sh, "sample", inputDir);
    } else if( local ) {
        SH::scanDir( sh, inputDir.c_str() );
    } else {
        SH::addGrid( sh, inputDir.c_str());
    }
    // Set the name of the input TTree. It's always "CollectionTree"
    // for xAOD files.
    sh.setMetaString( "nc_tree", "CollectionTree" );

    // Print what we found:
    sh.print();

    // Create an EventLoop job:
    EL::Job job;
    job.sampleHandler( sh );

    sh.setMetaDouble( "nc_EventLoop_MaxEvents", nEvents);
    // sh.setMetaDouble( "nc_EventLoop_SkipEvents", skipEvents);

    // Add our analysis to the job:
    MyxAODAnalysis* alg = new MyxAODAnalysis();
    job.algsAdd( alg );

    //std::string str1 = "EF_L1TE50_NoAlg"; 
    //std::string str1 = "HLT_noalg_mb_L1TE50"; 
    //std::string str2 = "HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50";
    //std::string str2 = "EF_mbZdc_a_c_L1VTE50_trk";

    //alg->TrigList.push_back(str1);
    //alg->TrigList.push_back(str2);
    //alg->m_use_trig = true;

    //alg->outputName = "myOutput.root"; // give the name of the output to our algorithm

    //****************************

    EL::Driver *driver = nullptr;

    if (local) {
        // Run the job using the local/direct driver:
        driver = new EL::DirectDriver();
    }
    else if (batch) {
        driver = new EL::LSFDriver();
        job.options()->setDouble(EL::Job::optResetShell, 1);
        job.options()->setString(EL::Job::optSubmitFlags, "-q 8nh");
        job.options()->setDouble(EL::Job::optFilesPerWorker, 4);
        job.options()->setDouble(EL::Job::optCacheSize, 10*1024*1024);
    }
    else {
        /*
        driver = new EL::PrunDriver();
        // GRID processing
        if ( username == "" ) {
            fprintf (stderr, "Need to specify grid username with -u to set the output container .\n");
            return 1;
        }
        std::string outputContainer = "user."+username+".%in:name[2]%.%in:name[3]%.%in:name[4]%.%in:name[5]%.%in:name[6]%"+(version !=     "" ? "."+version : "");
        driver->options()->setString("nc_outputSampleName", outputContainer);
        driver->options()->setDouble("nc_nGBPerJob", 10);
        driver->options()->setDouble(EL::Job::optGridMergeOutput, 1);
        */
    }

    if (local) {
        driver->submit( job, outputDir );
    }
    else {
        driver->submitOnly(job, outputDir);
    }
    delete driver;

    return 0;
}
