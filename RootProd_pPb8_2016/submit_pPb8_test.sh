prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_hip8TeV.00313100.physics_Main.recon.AOD.f774_m1736 \
    --outDS=user.mizhou.data16_pPb8.313100.Dec15.pico \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_hip8TeV.00313435.physics_Main.recon.AOD.f774_m1736 \
    --outDS=user.mizhou.data16_pPb8.313435.Dec15.pico \
    --outputs=myaod.root \
    --useRootCore

