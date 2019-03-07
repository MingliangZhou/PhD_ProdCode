prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_5TeV.00286328.physics_MinBias.recon.AOD.r7744/  \
    --outDS=user.mizhou.data15_pp5.00286328.Nov05.pico \
    --outputs=myaod.root \
    --useRootCore

