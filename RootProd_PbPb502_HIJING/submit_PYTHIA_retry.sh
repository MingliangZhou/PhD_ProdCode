prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS mc15_5TeV.420000.Hijing_PbPb_5p02TeV_MinBias_Flow_JJFV6.recon.AOD.e4962_a868_s2921_r9447  \
    --outDS=user.mizhou.mc15_HIJING.MB.Mar16.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

