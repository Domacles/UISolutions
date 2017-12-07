git remote add -f imgui https://github.com/ocornut/imgui.git
git subtree add --prefix=imgui imgui master --squash

git remote add -f GacUI https://github.com/vczh-libraries/GacUI.git
git subtree add --prefix=GacUI GacUI master --squash

git remote add -f Release https://github.com/vczh-libraries/Release.git
git subtree add --prefix=Release Release master --squash