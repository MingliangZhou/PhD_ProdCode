prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_hip5TeV.00314199.physics_Main.recon.AOD.f781_m1741 \
    --outDS=user.mizhou.data16_pPb5.00314199.July26.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

