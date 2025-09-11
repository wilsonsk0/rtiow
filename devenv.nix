{ pkgs, ... }:

{
  packages = with pkgs; [
    cmake
    cmake-language-server
    llvmPackages_21.clang-tools
  ];

  languages.c.enable = true;
}
