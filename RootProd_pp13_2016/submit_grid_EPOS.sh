prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_13TeV.361224.Epos_minbias_inelastic.merge.AOD.e3908_a782_s2183_a787_r6264/ \
    --outDS=user.mizhou.mc15_EPOS.Jun20.cumu.SPd \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

