prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_13TeV.00310216.physics_MinBias.recon.AOD.r8600/  \
    --outDS=user.mizhou.data16_pp13.00310216.May08.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

