{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  name = "c-shell";
  buildInputs = [
    pkgs.gcc
    pkgs.clang
    pkgs.glibc
  ];
}
