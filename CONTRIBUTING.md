Please have a look at [fork a repo](https://help.github.com/articles/fork-a-repo/)

..but if it is tl;dr

---

1. Click on Fork at top left corner of this very page.
2. Type the following
```sh
git clone --recursive https://github.com/YOUR-USERNAME/regionalizer.git
cd regionalizer
```

3. Type:
```sh
git remote -v
origin  https://github.com/YOUR_USERNAME/regionalizer.git (fetch)
origin  https://github.com/YOUR_USERNAME/regionalizer.git (push)
```

4. Type:
```sh
git remote add upstream https://github.com/JaroslawWiosna/regionalizer.git
```

5. 
```sh
git remote -v
origin    https://github.com/YOUR_USERNAME/regionalizer.git (fetch)
origin    https://github.com/YOUR_USERNAME/regionalizer.git (push)
upstream  https://github.com/JaroslawWiosna/regionalizer.git (fetch)
upstream  https://github.com/JaroslawWiosna/regionalizer.git (push)
```

6. Then open your new branch then open pull reguest [here](https://github.com/JaroslawWiosna/regionalizer/compare)
More info about:
 - [branch](https://help.github.com/articles/about-forks/)
 - [pull request](https://help.github.com/articles/about-pull-requests/)
