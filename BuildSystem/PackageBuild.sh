$1/RunUAT.sh \
BuildCookRun -project=$2 \
-platform=$3 -noP4 \
-clientconfig=Shipping -serverconfig=Shipping \
-build -nocompileeditor -SkipCookingEditorContent \
-cook -allmaps -stage -package -prereqs
