prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286711.physics_MinBias.merge.AOD.f655_m1533 \
    --outDS=user.mizhou.data15_hi.00286711.Feb28.ver00 \
    --outputs=myaod.root \
    --useRootCore
