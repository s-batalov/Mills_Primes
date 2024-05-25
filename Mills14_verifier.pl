#!/usr/bin/perl -w

### Simple double-checker for factor files; prepares a Pari/GP input and runs it 
### This script is for Mills14 factors; easy to refactor for 13, 14, 15, 16 ... (change the expression as needed)

open OU, "|gp -q";
while(<>) {
  if(s/^# *//) {
    last unless s/\s+$//;
    my ($a,$b,$c) = split;
    next if $a eq "from";
    last if !(defined $c && $c);
    print OU "if(((((((((((Mod(2521008887,$a)^3+80)^3+12)^3+450)^3+894)^3+3636)^3+70756)^3+97220)^3+66768)^3+300840)^3+1623568)^3+$c,print($a \" \"$c))\n";
  }
}
print OU "\\q\n";
close OU;
