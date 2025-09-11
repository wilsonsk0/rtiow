{ pkgs, ... }:

{
  packages = with pkgs; [
    cmake
    llvmPackages_21.clang-tools
  ];

  languages.c.enable = true;
}
