#include <iostream>
#include <string>
#include "doctest.h"
#include "PhoneticFinder.hpp"

TEST_CASE("song test"){
    string text = "nothing else matters";
    CHECK(phonetic::find(text,"Nuthing")=="nothing");
    CHECK(phonetic::find(text,"nodhinG")=="nothing");
    CHECK(phonetic::find(text,"notHyng")=="nothing");
    CHECK(phonetic::find(text,"noDhyng")=="nothing");
    CHECK(phonetic::find(text,"nudhing")=="nothing");
    CHECK(phonetic::find(text,"NudhynG")=="nothing");

    CHECK(phonetic::find(text,"Elze")=="else");
    
    CHECK(phonetic::find(text,"Madders")=="matters");
    CHECK(phonetic::find(text,"matdeRs")=="matters");
    CHECK(phonetic::find(text,"mAdters")=="matters");
    CHECK(phonetic::find(text,"maTTerz")=="matters"); 
}

TEST_CASE("famous quete"){
    string text = "if you only knew the power of the dark side";
    CHECK(phonetic::find(text,"yF")=="if");

    CHECK(phonetic::find(text,"iuo")=="you");
    CHECK(phonetic::find(text,"iOo")=="you");
    CHECK(phonetic::find(text,"Yuo")=="you");
    CHECK(phonetic::find(text,"iuo")=="you");

    CHECK(phonetic::find(text,"cnew")=="knew");
    CHECK(phonetic::find(text,"qnew")=="knew");
    CHECK(phonetic::find(text,"knev")=="knew");
    CHECK(phonetic::find(text,"qnev")=="knew");

    CHECK(phonetic::find(text,"dhE")=="the");

    CHECK(phonetic::find(text,"bower")=="power");
    CHECK(phonetic::find(text,"fower")=="power");
    CHECK(phonetic::find(text,"puver")=="power");
    CHECK(phonetic::find(text,"bover")=="power");

    CHECK(phonetic::find(text,"uF")=="of");

    CHECK(phonetic::find(text,"tarK")=="dark");
    CHECK(phonetic::find(text,"tArc")=="dark");
    CHECK(phonetic::find(text,"Darq")=="dark");
    CHECK(phonetic::find(text,"DARK")=="dark");

    CHECK(phonetic::find(text,"zidE")=="side");
    CHECK(phonetic::find(text,"sIte")=="side");
    CHECK(phonetic::find(text,"ZyRe")=="side");
}

TEST_CASE("alphbet per char test"){
    string text = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    CHECK(phonetic::find(text,"a")=="a");
    CHECK(phonetic::find(text,"b")=="b");
    CHECK(phonetic::find(text,"c")=="c");
    CHECK(phonetic::find(text,"d")=="d");
    CHECK(phonetic::find(text,"e")=="e");
    CHECK(phonetic::find(text,"f")=="b");
    CHECK(phonetic::find(text,"g")=="g");
    CHECK(phonetic::find(text,"h")=="h");
    CHECK(phonetic::find(text,"i")=="i");
    CHECK(phonetic::find(text,"j")=="g");
    CHECK(phonetic::find(text,"k")=="c");
    CHECK(phonetic::find(text,"l")=="l");
    CHECK(phonetic::find(text,"m")=="m");
    CHECK(phonetic::find(text,"n")=="n");
    CHECK(phonetic::find(text,"o")=="o");
    CHECK(phonetic::find(text,"p")=="a");
    CHECK(phonetic::find(text,"q")=="c"); //50
    CHECK(phonetic::find(text,"r")=="r");
    CHECK(phonetic::find(text,"s")=="s");
    CHECK(phonetic::find(text,"t")=="d");
    CHECK(phonetic::find(text,"u")=="o");
    CHECK(phonetic::find(text,"v")=="v");
    CHECK(phonetic::find(text,"w")=="v");
    CHECK(phonetic::find(text,"x")=="x");
    CHECK(phonetic::find(text,"y")=="i");
    CHECK(phonetic::find(text,"z")=="s");
}

TEST_CASE("game quetes"){
    string text = "war is where the young and stupid are tricked by the old and bitter into killing each other";
    CHECK(phonetic::find(text,"Var")=="war");

    CHECK(phonetic::find(text,"iz")=="is");
    CHECK(phonetic::find(text,"yZ")=="is");

    CHECK(phonetic::find(text,"vhERE")=="where");

    CHECK(phonetic::find(text,"dhe")=="the");

    CHECK(phonetic::find(text,"iUOng")=="young");

    CHECK(phonetic::find(text,"anT")=="and");

    CHECK(phonetic::find(text,"ztoPiT")=="stupid");

    CHECK(phonetic::find(text,"drycced")=="tricked");
    CHECK(phonetic::find(text,"triKKed")=="tricked");

    CHECK(phonetic::find(text,"fi")=="by");

    CHECK(phonetic::find(text,"uld")=="old");
    CHECK(phonetic::find(text,"olT")=="old");

    CHECK(phonetic::find(text,"Pitter")=="bitter");
    CHECK(phonetic::find(text,"biDDer")=="bitter");
    CHECK(phonetic::find(text,"FYDDER")=="bitter");

    CHECK(phonetic::find(text,"yndo")=="into");

    CHECK(phonetic::find(text,"qylling")=="killing");
    CHECK(phonetic::find(text,"CIllYing")=="killing");

    CHECK(phonetic::find(text,"eaKh")=="each");
    CHECK(phonetic::find(text,"EAQh")=="each");

    CHECK(phonetic::find(text,"Uther")=="other");
    CHECK(phonetic::find(text,"odher")=="other");
    CHECK(phonetic::find(text,"udHER")=="other");
    CHECK(phonetic::find(text,"OTHER")=="other");
}

TEST_CASE("extra"){
    string text = "C plus plus is the best programming language";
    CHECK(phonetic::find(text,"K")=="C");
    CHECK(phonetic::find(text,"q")=="C");

    CHECK(phonetic::find(text,"blos")=="plus");
    CHECK(phonetic::find(text,"plOz")=="plus");
    CHECK(phonetic::find(text,"BlUZ")=="plus");

    CHECK(phonetic::find(text,"fest")=="best");
    CHECK(phonetic::find(text,"bezt")=="best");
    CHECK(phonetic::find(text,"besd")=="best");
    CHECK(phonetic::find(text,"pest")=="best");
    CHECK(phonetic::find(text,"FEzD")=="best");

    CHECK(phonetic::find(text,"Brogramming")=="programming");
    CHECK(phonetic::find(text,"prugramming")=="programming");
    CHECK(phonetic::find(text,"froGRaMMing")=="programming");
    CHECK(phonetic::find(text,"BRuGrammynG")=="programming");

    CHECK(phonetic::find(text,"langOage")=="language");
    CHECK(phonetic::find(text,"lanjoage")=="language");
    CHECK(phonetic::find(text,"LANjUaje")=="language");
    CHECK(phonetic::find(text,"languaje")=="language");
    CHECK(phonetic::find(text,"language")=="language");

}