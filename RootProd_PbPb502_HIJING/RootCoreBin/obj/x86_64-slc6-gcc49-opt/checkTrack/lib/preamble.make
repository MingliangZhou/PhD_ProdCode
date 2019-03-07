RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/include -g -Wno-tautological-undefined-compare -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=24 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DASG_TEST_FILE_MCAFII=\"\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"checkTrack\" 
RC_DICTFLAGS = -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/include -g -Wno-tautological-undefined-compare -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=24 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DASG_TEST_FILE_MCAFII=\"\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"checkTrack\" 
RC_INCFLAGS  = -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -I/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -DROOTCORE_RELEASE_SERIES=24 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DASG_TEST_FILE_MCAFII=\"\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"checkTrack\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_BINFLAGS  = -L/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib -L/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/lib/x86_64-slc6-gcc49-opt -lcheckTrack -lInDetTrackSelectionTool -lPATCore -lxAODJet -lGenVector -lxAODPFlow -lGenVector -lxAODBTagging -lxAODCaloEvent -lCaloGeoHelpers -lxAODForward -lxAODTrigL1Calo -lxAODHIEvent -lxAODTrigMinBias -lTrigDecisionTool -lTrigRoiConversion -lTrigSteeringEvent -lRoiDescriptor -lEG -lEG -lTrigConfxAOD -lxAODTrigger -lTrigConfHLTData -lboost_system -lTrigConfL1Data -lTrigConfBase -lTrigNavStructure -lEventLoopGrid -lPathResolver -lboost_filesystem -lHist -lxAODTruth -lTruthUtils -lxAODTracking -lxAODBase -lPhysics -lxAODEventInfo -lEventLoop -lProofPlayer -lProof -lHist -lTree -lSampleHandler -lPyROOT -lProof -lTree -lAsgTools -lxAODRootAccess -lNet -lTree -lxAODEventFormat -lxAODCore -lRIO -lAthContainers -lAthLinks -lCxxUtils -lboost_regex -lboost_system -lxAODRootAccessInterfaces -lAsg_GoogleTest -lRootCoreUtils -lboost_regex -lTree -lHist -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_checkTrack : dep_checkTrack package_checkTrack

package_checkTrack :  /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib/libcheckTrack.so /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/bin/runpp postcompile_checkTrack

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib/libcheckTrack.so :  /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/MyxAODAnalysis.o /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.o | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/MyxAODAnalysis.o /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.o $(RC_LIBFLAGS) -L/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/lib/x86_64-slc6-gcc49-opt -o $@

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/%.o : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root/%.cxx | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/MyxAODAnalysis.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc checkTrack $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/%.d : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root/%.cxx | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.o : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root/LinkDef.h /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.headers | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc checkTrack $@
	$(SILENT)rc --internal rootcint $(ROOTSYS)/bin/rootcint $(RC_INCFLAGS) /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root/LinkDef.h /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.cxx /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.headers /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib checkTrack
	$(SILENT)$(RC_CXX) $(RC_DICTFLAGS) $(INCLUDES) -c /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.cxx -o $@

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.headers : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root/LinkDef.h | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -D__CINT__ -D__MAKECINT__ -D__CLING__ -Wno-unknown-pragmas -- $@ $< 

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.d : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/Root/LinkDef.h | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/bin/% : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/%.o | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib/libcheckTrack.so /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/bin
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -o $@ $< $(RC_BINFLAGS)

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/%.o : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/util/%.cxx | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/runpp.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc checkTrack $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/%.d : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/checkTrack/util/%.cxx | /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/bin : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

postcompile_checkTrack :  /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/lib/libcheckTrack.so /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/bin/runpp
	$(SILENT)rc --internal postcompile_pkg checkTrack


dep_checkTrack : /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.d /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/runpp.d /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/MyxAODAnalysis.d /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.headers


-include  /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.d /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/runpp.d /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/MyxAODAnalysis.d /afs/cern.ch/work/m/mizhou/SUB_CUMU_PROD/HIJING_PbPb502/RootCoreBin/obj/x86_64-slc6-gcc49-opt/checkTrack/obj/checkTrackCINT.headers
