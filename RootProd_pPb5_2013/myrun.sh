#!/bin/bash
 

echo "Starting the run" 
cat input.txt | sed s/,/\\n/g > input2.txt;
echo "List is made"
 
root -b -l <<EOF
  gSystem->AddIncludePath("-D__USE_XOPEN2K8 ");
  .L CombineTriggers.C+
  .L extractor.C+
  extractor t("input2.txt");
  t.Loop();
  .q; 
EOF

echo "DONE RUNNING THE SCRIPT"
