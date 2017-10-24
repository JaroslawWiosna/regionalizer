

    rm -rf ./clang-format/ && mkdir -p ./clang-format

    curl 'releases.llvm.org/5.0.0/clang+llvm-5.0.0-aarch64-linux-gnu.tar.xzz' -o './clang-format/clang-format.tar.xz'

    tar xvfJ clang-format/clang-format.tar.xz -C ./clang-format

    rm -f ~/bin/clang-format


