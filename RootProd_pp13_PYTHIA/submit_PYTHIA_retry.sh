prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_13TeV.361203.Pythia8_A2_MSTW2008LO_ND_minbias.merge.AOD.e3639_a782_a787_r6264/  \
    --outDS=user.mizhou.mc15_Pythia8.ND.May02.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

