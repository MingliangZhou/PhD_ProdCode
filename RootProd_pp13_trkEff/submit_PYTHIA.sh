prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_13TeV.361203.Pythia8_A2_MSTW2008LO_ND_minbias.merge.AOD.e3639_a782_a787_r6264/  \
    --outDS=user.mizhou.mc15_Pythia8.ND.Nov02.pico \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_13TeV.361214.Pythia8_A2MSTW2008LO_minbias_NDnch120.merge.AOD.e3908_a782_a787_r6264/  \
    --outDS=user.mizhou.mc15_Pythia8.HMT120.Nov02.pico \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_13TeV.361215.Pythia8_A2MSTW2008LO_minbias_NDnch160.merge.AOD.e3908_a782_a787_r6264/  \
    --outDS=user.mizhou.mc15_Pythia8.HMT160.Nov02.pico \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_13TeV.361216.Pythia8_A2MSTW2008LO_minbias_NDnch200.merge.AOD.e3908_a782_a787_r6264/  \
    --outDS=user.mizhou.mc15_Pythia8.HMT200.Nov02.pico \
    --outputs=myaod.root \
    --useRootCore

