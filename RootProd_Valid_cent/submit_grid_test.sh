prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286717.physics_MinBias.merge.AOD.f655_m1533 \
    --outDS=user.mizhou.data15_hi.00286717.Mar24.CENT_test \
    --outputs=myaod.root \
    --useRootCore
