#include "array_view.h"
#include "file_io.h"
#include "utils.h"

// void doSomething(const Array<Variable>& a, const Array<Functions>& b, const Array<Operators>& c, const Array<Types>&
// d)
// {
//     for (int i = 0; i < abc.size(); ++i) {
//     }
// }

int main() {
    std::cout << std::unitbuf;
    Array<int>    ar{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Array<double> st;
    int           inta = 0;
    std::cout << ar.find(10) << std::endl;
    inta = ar.find(10);
    try {
        std::cout << ar[10];
    }
    catch (...) {
        std::cerr << "error";
    }
    std::cout << ar.push_back(100);
    String str;
    str = "hello";
    str = "gtiy" + str;
    std::cout << str;
    str += "gtiy";
    std::cout << str;
    Array_view<int> arv{ar};
    // std::cout << arv;
    *stdout << arv[0] << '\n';
    arv.setViewStart(5);
    *stdout << arv[1] << '\n';
    *stdout << str << '\n';
    *stdout << str.find("hello") << '\n';
    str = "";
    std::mt19937                       gen{static_cast<std::mt19937::result_type>(time(nullptr))};
    std::uniform_int_distribution<int> a{'a', 'z'}, b{'A', 'Z'}, c{0, 1};
    for (int i{0}; i < 10000000; ++i) {
        if (c(gen)) { str += (a(gen)); }
        else {
            str += (b(gen));
        }
    }
    String_view strv{str};
    strv.setViewStart(8422975);
    // *stdout << str << '\n';
    *stdout << str.find(String(strv) + '\0') << '\n';
    // str = "KIqzJiZKaCLEpDQnJnCazgEqbjmeqXqSIZqTinvJPncdmIitEoRExJWieNGLtTRutRiwqhadgCrpidOjnzZSqyyulhURDgufRRRMkqoZ"
    //       "KNQlQh"
    //       "ZTDSuzXFKcjMDFEnQxXAjTrCbGHkYFeCUyaCexmxOpvqfXyGaMtzjaUVdNsQhbbfEOOFdSZsherpzhXhEGJqxEoNGkwuyTXHFDMJltOa"
    //       "xQbwOT"
    //       "PmkoUfgFUDNzaQgNcHfQmGNAXoHuxeNJRfzLrqTtAIEbPKSDKtWZNPwdFeKVyvoRUThHvmttAZeWduywlbydLosvJXznHPWPCJBPEFRg"
    //       "cREnKC"
    //       "gyoQtLImvcOSNHXKLHrLctrqgsLspnkFFsRJVnwMZVYQggvVvyJnlXSaAsLycCMdDEDuMUGfdyMDnsABzlwvtTtoEPoIFRUFcpArvCeR"
    //       "EwRdTT"
    //       "EsCXecxRYamALUUCsWtPdBcCLNoxIgbZilZjkTHZaMquEjXfezYtMWgOeYxpKkETIITnOSKuFuGBmKjzCqeIVjjxAEIvTcbWlBdhAZdS"
    //       "lNAWxF"
    //       "lnkQiCwglNqeNpoHqGMalVUznjyGsIYajaHGMpqGWfKvaCIaiymyDOAksCJtbhGPcfZVpruGomvAxYcfyjFyCbAxuwqsQELjCQSkamyu"
    //       "AFsbha"
    //       "twaLnygIGcRyOPcVNsyQnEnFMQyagtOnSSCYETRQTTJYvbDRgdKCCNcGODSFtcjHjJAPeIvDmzNbESofMCXWJdwOWdkwZhauKHLLTjDz"
    //       "WWHTqU"
    //       "qBdyCNmXgvuDuwXadNMjhztJCWbZbiAyvsjAnTLCLxEMidpKsDnPNrbIwPlRYKOwBDKBUPeiKVltOLJWDHWYuwMgKHWtasNYdozhPLqI"
    //       "FxEiRi"
    //       "BNiourePLanHjlqRYttReSgQLFPQltreDhdhplkDJRwNaQGCUqvcivtaBvXXaWxnwGJzkoXBQvtFIcLrdrQfAYuJaoeLsGhpmDRtHeWY"
    //       "dauUuR"
    //       "xzPhqFPkNPjmKllVTWQiqVhJhnHIUwwJvHgdjtRqNqbndjpxJVmBcbKzkUlfQffvPkZZbfxWeMaQQzAvBOLgwxBGbiDelRipLWzCtKav"
    //       "pUUBTl"
    //       "EFuZFLnQNRTzsxyPokCHpoXOTagsYlREMdnrwvTIAGSAHmpDUaotsdOZXnLZqgXGARXNJxyocgPQeHDinaafTxbZmgZVHfZxGuMSbVPH"
    //       "XZyqik"
    //       "NLTANBZjYvvoqlAFROkVWIWhFQMQvWiNvznSYsptRINjybymImMVHWNoCUwyKcArzwBvhZNqkfvmfKWstljqIpExegqUOIDxgGztlLAn"
    //       "kfsWIs"
    //       "OIHQGsrTdwoFQQGlZZUKxPgUnHJFkhUFYSeZbQVPvQgpCLBhbifVKeayGCyRVvDYKKKNfDByIlVMaNWwBPlgIqlbuRlZfdSzfWeHonLa"
    //       "POXTVK"
    //       "MNJuzRPcwTbebgQsYgYKFTmPcjGEatYSsdyAOXiPGKGFRpkwKPsDFVrEBIDlaGjZWTOkbGhxXgplWoodKTFhsWUrsddGeyEKnlobUfKn"
    //       "tqLcNJ"
    //       "pWPYVTZUeBFLftfoxvRlIVCNZIuAzYdPUEmcwmyrQLzySKoONOPlPGVrpQjNifqiitygtJmVMyRxzGRGzKEdhGiPgnLqsJttHnpgAzuf"
    //       "PNCRWL"
    //       "zvOklvROZwcIjelpNhhDSmxhCZPhjvYOzfEYJchjcIbpYlGnPDFEohfPRQlhRkDgsOUGqzckyRvNzMNtlWrYEWBbZLDunlUvGvcVbJbh"
    //       "tmYfKu"
    //       "AgewBsZdgUiJjglFYCWWMVTzAYwiHRsMAMFPbAZkfTYtgKsKyjVZWOlVqzuMFmbMMhyrOUsMOeKCghmFWDPoDhLgaCkgBjWnwLmFbSLd"
    //       "xUfBCP"
    //       "RleMCXYQIbeARanwmmmxFAOOXfBwAiexIRhFyWuCQQiYqaZuBwGmeOcZHIMGUSaNvZrOsbbKQgcJTWSSVFDPprDjoFIZVxhHjcNRzTUe"
    //       "dJQJCY"
    //       "QpNyXfHkdpQDqfkFZGRingFWkLSbXuZOoALMeIJbxxtRtaBFXdZmaxEbBbsMSvmktdbEnkHroulrfROZOXXjTUribWRIKyWBpNvdGeBi"
    //       "WDGcYH"
    //       "htXNfJPNemuEagwbBmsCurcQhkVVrsFTdQrFOTvLvRZBLMGAIYacQmQHFtUgTfKAGJlcUiHQGvNLuuNsgtfMmuhsbFarrNoPemVrmlcI"
    //       "NTwsZR"
    //       "mYEvFuLYgunWgMBCmAjtRDKmniCJokXhTgQffeQfGoNpeBVJUHCLyRHkUEllJMmHdyYdbqjLeGbsFyRKqBoroZjEgMExUKqUGmtBMjqV"
    //       "qNsqVb"
    //       "dHwaTCOYxbKpqvDZnYONJkLZHdEzZUVdghuqZlzDadjROwMTVmfCSQzyjioHmTSQfMqsjdjMrruXueksvpvjDaZRSjDEHjKeJveLeKRl"
    //       "WpBozX"
    //       "xPpCocqKoxKRhveFfHIqlkXhtceVxOajsofixLvtPUAFfoQihHNxzZCunfVTgRgryQvCGkrGGgsNGuVikKLQNOFJXICrbbIwFZbYvjCl"
    //       "mzjZgN"
    //       "YtOtdHVAifxRkBITVMnGXOquJMSqUJRAnreMtthpfaTCLgrdSDgsdnEXAtfOIFgFNWNuqRWUsxsiRFQuIzLgRjISAcwLfAyFTEgdZJQo"
    //       "eVTlKb"
    //       "SvwLBgTFNAnwZECCPxelzRnAGjOTfjzIplkaCsGIJNHjMzybTEAtyNVSHRABVcSTLWXiFyxhEzIiaHvDMPIKXXbHveTnpovtfDvVWrjf"
    //       "fSEFgd"
    //       "tOrgHLwzdqyUBAPVtixWlAiDuvvoysISGyQSLRixDiRNxAuNJOVTtsASleLEXqIDNKzWcRTERdtqqYYpKePgFREJPwwrxzwKAmCOJwog"
    //       "IZeiRK"
    //       "aioUGuIISzRuoQCvKPFBmbFqoHGSEelvJTGwCdlDlLlXtAOvOSfxqOKMUJMvIjZbeNexrsqjdkUYrHzXNZKtetBLaMLbpPSbQJEtjwkH"
    //       "BdvntJ"
    //       "JYMtmHHqturNTIdIrtuRINGisdNZKuEBzktXgkuTuhUXieFHGDsiagrqzmwbgquZsTkkJDQLQTLHRMeKbCEcNWLexzvHoCSPdXepuYXr"
    //       "ztFwDN"
    //       "qWeocRukLulrFRKSjHlUcyCxLbGffBemRlSIRAQaOWjRQeGpFGbFgykwApQIVPfVcUQaJVCjyVFCDqTVCIRjNeOwqlUbjdLoMKTbDEzx"
    //       "fTQHKW"
    //       "OdASSRpfXrbqFZhsvAvmSoBfiITVORJFQawUXPIzXbuKTaKFYEgxWSUztmYWpbTKtCqOLjYuOpxSOluDHlvBKBDESONYFqMdTjTPosHL"
    //       "zIHUgu"
    //       "amfCxCoXyGYRBCyBIAovXasYWmPrHvnMjuTFRneBKgxthBQsbNoouKpsVlRcRTqVqZfqJaDdtrDWFMcNcFPJFHkkDWkOImtXtLrIgejG"
    //       "lamsQq"
    //       "HSYnKxyzeNrnaZleuBSPvKucImbZPiKTtRMAfQAqzdzFTTgJuYfdkgetkZFocRIAlIouUChyvEMIprqnSYBEQQDXTMtYOCrFosGCUmdw"
    //       "wnOhjf"
    //       "ENYbuVicRZLctgAmBHpkkWmhMwJlHBQDPFhXiXQzTHjOjGXfghfmIIIsHpiANPHOTLQfmuJIsHkkluAQfZjSgIlmFJvmLuyUJqvoOnCN"
    //       "ZoQBaY"
    //       "fmdXOzFpQhluVhhtQKgmcgRJVOTynJXRuIBiUdTftVpOMOhBguMrVfQzkbvlXninBKxILaWFhfgjtsrYoKXBRfVTchrYzIZJrBHtKrHa"
    //       "LCBTPE"
    //       "emceqKYYAyDjhAsOVooeOMLlCYaFOjnVVoemUznrEwUMbtYGNtsvBSsmhwpcvQYVWZKfaeRpuzWoayCYKHbaHrFsWOaXeXKQwjTvariW"
    //       "xGufHh"
    //       "qsJjBEDMmhtXvJLDCACCzkbmXIcaNFoQSXqAstUbBMLMXrqPqgdhnKSKGqJJmxMHABuNxbmhnlwAeVjOplFcQIcKlrzJLlgGjZUDjNpN"
    //       "LPPpmN"
    //       "oSzTzaGtAJXKKmLWUSEUOwinFoHtwriopJYOzelMicQuLEXsQQoscrsfbGneiWtUxjuCYIpWTbdDncSdhrQmnXsCgJIyDLKWKAcfhECk"
    //       "iXbZnj"
    //       "VHXMaoXSLnkMcxfzTPNHKAEyoMyzAqpQHKXXhqbvsvOlFCEKLGkgUJOSzlNIfJaQrdHZCVNiBgcBxsbzoqRejncpViKntJNEjnhmLCyC"
    //       "gVhthR"
    //       "dJmILNtODCuAbtKXTONxcazvCIZndEEMYhCRwIHTminTPkmhzseEocPjvzFFAtFgplBysKufQuMRBKLvqXGkdoXFDSwWmfKRwbCkGYoN"
    //       "gyvNDn"
    //       "zfRTzUUnbstuXBLnpSkvsKcNncnxmEGjJvheFVyisxxoSJSumKgPwclVEExGlYDODQgWgpCVePdiGUzzPXgaWUkSlACbVUJXiaJNWUka"
    //       "HpUaYn"
    //       "sHjfJMmWKQjIOsdDpcYBOGyBEaZlzpNNNSAjhEjDHXOkZJCwbfxvgjrJVWgoKfPcAvqqLUirUYkZXgWyxeoXEHRaTCFUGMidKaTzqlXv"
    //       "PYrNAx"
    //       "uqMFPNbNNgbTFdglHOpalFIaPlVKXSbknjNVlZNeBzpPcbsuEfscAKwFqLFTpTpUHHjPtCpnezZpAVqtXdLkMByaFqGNfUfZVnDWRDQk"
    //       "TscWOs"
    //       "kqljBKIiCNGeyGDuGFCbuXiYxoLUPOxudmApdhkXWvXgtkvEUBWHEpYaULHkStIvJVpuOILAjHPekGpRhwnCIRsKiigTKdDguEOXEdPL"
    //       "lqybdh"
    //       "iSivSaNCfHOFdQuNECYdoHjOXBNSgHjLSUHVNmwsAtDNIzdXEMhIXWGrgMANEaNeUangDVTSzkqTmaskDpgyIlrVlXVNaLkbwejZyxok"
    //       "RVIbyu"
    //       "yOzpxPwkcMEPuiezVTLliyvvyeNrWDOHeFSjZmmyxeQTqqWYfyFaNCXiNXvsZvnjRRNOKgFoQSXGAjFCEDpdxHTRkjzOotZbSTLZVRTz"
    //       "CnklQB"
    //       "HpakDDVqMcWOnyDmclLHDTiUThjjUtfejGkJjzIEuqfhVFtfBTuKZpynlJkPOlNaWyXdvTHnqjeyBCGObmvtjfAIAOuFxZaErbOmdkLh"
    //       "BCsUhK"
    //       "JwImfEOKZSTYuXpElFEmwBcilRVeOIvQWLXuKdhxyBXlbRXliPIjCmgXHeAwsWpbDiMzgIYyytoiqYzmAdNKCLrDEVhEpOtUbcXASnUK"
    //       "wUebWY"
    //       "UbqxcywjEuKFVaOiLLRHlzcaIXZOeqaKaLDKZwpUMgYfKKGADrcbqvQZKTVkjFoErJUHiKAGNzfgPFWVAzeOxfPWxmOpGzRcMMaqZeKo"
    //       "osHngD"
    //       "yStkpRBzIMZdfFpLIlHNQCVltqDTCuMbFgHzglXUioTvADMRphJipwJteVJCWSwKDvnHbwDbbqyuTVisSyExQnjCcLhMtsAJZcKBNUks"
    //       "oOoUAz"
    //       "LnHbwuZkeVxaYPeULATIoNEvfuuVPnWsKbjMUcpQyvFdctHeRmiuuZddQGHLksBpFhSoWaNXhhZlaEmFNFYNOkKbgeZHncBHTsVKeJME"
    //       "ZWMumy"
    //       "nkTdwltWHNwbgcxhyXmPhxcxsCymDSFdBfzmBsEjzSecxxSkwLhrgaxNcpQEiLOOwhAgrbQkavhIORNCObDItOYTfhTEoYsbiTJhygpW"
    //       "GybFuw"
    //       "pngMjXVVhawTdcuafbTEfbhKHqHfWUeAqeuPRYFntWhEfNGvtBTEPvcaMMbsGMzSCGWmtlgwqOGQBtKSPfZbgRPYmZnmHECaCYzcGTEZ"
    //       "cKEBgm"
    //       "YJrYiKbTLGDizcqviFfHoIcCpFBvLBuMuzklOgXFuxMYyYOgcNFSQubnDmtjmidFRAivmdfjtomdcidmhDVrepruaoLHALvfkKbrLxsH"
    //       "EKviAK"
    //       "qBgEfBzpDPSWKRARTrUIrwSUHiAFnDmHSsjWkenvxmpjFoAVrpcXecAWcNxSamXmIDfDPRdqgCxXcLFRdlrrxDJqjBVRnzTJjBMEyUGY"
    //       "SlkCYN"
    //       "afzwLuKXFQwURTJsqTcuTwXtHyBzDKNRIYEefXCXVLaNwdjRnpZmnswIJbzppYLjepxGEZaiMkMYHHyFgZtXbhQIurPanvlHmhQzffcL"
    //       "PZJrgX"
    //       "fLtoRtpkDawlXtURZbInDpWGSleLJPkaWVUfHPqRUlrUgeXMjpRafmgFccSNCThakyugQIlFBeWsKdiVjexMnUdNOrHTgneBHgsbaluL"
    //       "EglryM"
    //       "iemNBDZctKWJjMQbyEGmZqoThIGZzPxXhTqhLlORGUvudKfrkPpnczdUMmqZQaTURvksmulPIsIlXEeByWdDfWxiJpfrSKtvPekjsGlk"
    //       "PdmAIH"
    //       "csbtriiFiTJFthFlcYtkrhZDFSiobyuDrwxUxZIYqMbFPovjsMiOVfWgCjiUAtDRzUMcAzFXKMKBWTHWHnTbgFWbcGHQKcwVlGnZNSmX"
    //       "mTAfrY"
    //       "sSGKgcehpFxiPAIyERZHpxatYTAXHgALMgZeTSwhonpijsKGVeZYGSiaaoiXmskMGssVhHUzkuOLYesDVKRHZMVMveNXlWqxONRAVLmo"
    //       "sofiWo"
    //       "zhioQLhVDyTBNCyihRDNKOpLRagmTJQHeNYtzrSSapRXaRjKIoMUaCBOzqKEPyGfEAJrsfMjDKOJGoYJsOitNdIMHfShnmAxFypTXsrz"
    //       "sqCWXY"
    //       "DcTWZRekvXAsQntWxbINULytnxYtKFsGNdrYSFvMyDkkOkBHtpENzVUYNIsoxzpbMoDWnvIhYRrnyahhgLUaEEQAfSLDpvJosFuAkStZ"
    //       "IUfsQz"
    //       "BmsNsPKUdcZWJJisILfgUDyRIsyIGMgCHZilkpYrxjdCnVOGilozZffdTbPmpBvKNWlAkvTjUgaQJrMtvgdCsrYbNOgryjZvcosuRTfx"
    //       "RRFycm"
    //       "DEQTSzDQJUwiiNJhYAvKXlAwVKsEzJWvGDendnRrxjuACwPNTKXLjWJagySbREgvDZFpGEnVViPZDkeueTBxBKxVLXUOFvdwVJJsDqua"
    //       "mvovOa"
    //       "KYwyuBjKGqgVEUtgQTXEsKTTwQCffCxWehfxLKKTlobzgKGPVYPaXvXDjcVBBlIDbNPWGBcrudGMfeoIZlPvKdnwUxGooZdgthBSrqZT"
    //       "KCsERw"
    //       "qqfIOUdwlzxtLZogLpHUZqwoZRjIEdLTRrzJCSRMofFCmxHPtBnalVICRDOQbztViMvLnDkBFepWLJeHSLUJuCviIPgkwGDrdUlLpSeU"
    //       "GJOGUs"
    //       "HcumMseGWAxzfedenFjhzPpEmoVYgoczIGsuUgfzjIDjcXjuTLzvscAYmUzoAOaMneWyNqbMxtQpLrOopYavkuOmROBYHLzwIbQlpjge"
    //       "wYGxpW"
    //       "AeEUOrPbsfBcrlgyTcFaeUlLiMXLVpDUkUfSzoMLRTnRXvRykPaMDhwTcFlvGQQaXKwsvaECQEluplBKMZWklnehgcPsoKDotGvHxRKZ"
    //       "IMcKsW"
    //       "zMhSGZtFowQGgFddtJZcBAsIWfqonNFdVZpXtEUzMozwNBjkhnOKMynuvoyKrgexGaTpLfJMDjtFCHezNGZqLRuVUNRscnPOkJMEnOPz"
    //       "IjVsmz"
    //       "yXuQwIbWYPQblbQQdvRoHUqacdIFXZQdgFnkEFVzHVpdBHUKLXmzjltuRximQljWgejVyEBKAjMmbqmrOzCueKrfbBlGYVwlAZXKLOtm"
    //       "fugZeR"
    //       "DulKepVDZnTMuRpoeEUfZFIFnNVOFThqVyIkYtXsrXHRgEBnDYDdaiOLZCrdGNbRkzgtbaqHwRfICAwxckyqgrTOJnjLauYXpQYwyxtd"
    //       "HWMxFI"
    //       "tRGGbFrwwimnclvmlLsSZNemwsBmTcImCZmwVAjhoxihORmLLRwIdBAjDpiFIhsiwjvOPiZRLuPXEZcHBAKHjbBaZJgxCXAJLTmLXdDo"
    //       "ZibLjT"
    //       "ZLEvWbqqypxIhDyrkryRoINutKanntJhoxyOeOOrzgcyrLzHnAaeDXaSddwSSnfiFdgXgjMpfdPUESezAyzfWdqbAvfOXRkobmRuJOtL"
    //       "rhwljU"
    //       "dMnFRlzxlNrlvUCUUzOYztAjHVJlPfOcPbDEZtHHvhPTSRNmicEiBnnSFesByfYJyKdsiGbwKwFQbDgVqclPUomNpioUJhtmopiHkXnR"
    //       "TVyUEh"
    //       "owrByjbawsqzOoBZpGCtrRRyaKdMdZlUkvsEEsAaHCApSPimAieqgVLwYJRsEUywITEwUfTkOsaCnNhBuwdIWeGIufSJDngkAORGKOQS"
    //       "JeUDBw"
    //       "rpoPiqulockUJdkQAoNgPJtuyZYvNItHixnTKCkooauPlqFfzFNosjkFZanmTOjRePpzuAvTXrlmEyKHySNpSroofBozGXnSskCaLFxd"
    //       "UUnEcg"
    //       "WEOzQmLMVNjEdjNLauCsnuvKZhvcrcwsfPvUcXHgknNXOejccnpuUlCPLfCTveQfrKWiyWOWMbgMjflnwrRBCWdbyqmrMEWdHFdjQaVx"
    //       "vTFOqg"
    //       "rvSjJEgOUavbXrHyScbnIYrwSSmNbMMlhjEQwzKgznABOObjhuWgvbsApimgTNmnunKrWAnNVDtnpLtLluCayDyRdKLkxDyRnGcESuoG"
    //       "DUJiCa"
    //       "LNisrzfJIvAOQUYjwOHfdCRcKmcMXZGyTeUbmHBphBDGdAggMVcmFVJCTpIFkndRjcsNdYKfsgDaimcXRBJrKNjopJQEWNqPDlYlsCRl"
    //       "JqKvvs"
    //       "sQDJyOiHGvcXUHExhPYZeFclStislLdYXqXKUdaKjXrakJuMiuzzBEUPlihMqhdWzttrzlLYomdcNwkGpOMWeRetzRmlgDDeKnooOuyc"
    //       "PktZFg"
    //       "KFJgQSQBCFbnZcGdcagWAXzXugLUOuJZeZjYaTjAVPWBEYusXcuBnROcCNFnUcXyUumyZtZfmYUXxbLXWJjKHRyxbxmqifvEFRRsKDOW"
    //       "FLAaHN"
    //       "RqyQhTAzPoDqeRDzdomnptcCUiTcjNyARQtGxcmMfNqXVuZEaSFRFGbhsmQiWUZvCKKESkIXjewpUDegsqGWdZyVSLuhcEysQbhFcYQG"
    //       "JQgVOZ"
    //       "ERxAmbyUKFTGNiaKsoZFBFgdEaOuJCuqdYvsfhETYHIajFRkEgAzaxALDCjFUoRcsflBmWxbmtNVXNJLMcVbPEUxiZfaYztZZkTlUjmr"
    //       "XqtBPB"
    //       "KokgwttQiZQRzUkOgAjiZgOSHBMwHVfDGfyaIRTnAcjvzKkCekKcoCsBoepskndkbOpkeAQEbGXGvroPNsADkyleAFOTiBxiKTfPWcAh"
    //       "PsUJmm"
    //       "gwbLOywsfWqQGdHlijHdmnYBDRLJASmMqfqrgvPJhTeaPikBYTqWXHENdweYHLGBCxytIloYmSssgXLYgNVzuqhLqjXbumqDhZUblKgY"
    //       "XjiKTd"
    //       "SAwsADvKfcnendFEFJnZaWnxCuHNZsGenceFNYtUTuyWciFVhcWFoTvlrJGmGOtEBmiCbkuLTVLNtOQUHwJmdEBIaKdUlsAMzNhmUQBP"
    //       "cGOHfV"
    //       "ScSpsDJNNZJfoEtAbSuIDsDnKydiQlcIHFZfgJtKSgDdtsRjFRFBVHMyfnLSQoGNwESSHCOxmTdxhyYKieVCHMRtAgSjrPlIJALQUQHu"
    //       "tLSNff"
    //       "WixMKxAhVipfiNVqqnIVSWkAkAWtNzuEWiHIYScqosOMsuijogtppIMuXSXDHhcsTrLIvRDbZHMLBpRxzFiiGZACEbgJPAbfzASkKPjO"
    //       "Whthkf"
    //       "ncZPIPWeXtCqmusRohIqSNmldcUzmgmlUpDseKVFJVNOoUzYlKmCDidAQflfbJUZCLSzOhWGZCrzpYkWhHtBHHDszWgPUmSXsBjobOKG"
    //       "TQxsTX"
    //       "vZVyrDjDgHbbMYWZAwpvoSNvokuMZzNapXRlWKjwSEySQspoDfcLwLSRXOAvKRdnFGBHruDfOSNrLkeLAsZUtiIOtNWBeOBapounIhnv"
    //       "PuPuSU"
    //       "lkISvNxvMZUVGYsQXSYrAXjbPLRfskZZDLneLkCmQhBtDdNMDyOBrdBkdgCDcSqNCFLucEwjepnIhWyHaqoUoKOzUGFyqglNiLdvdBEt"
    //       "BSqtZj"
    //       "YxNlkqEqhRyMIhdfTNuzykbVWbvPWnqlCFgikhEarQQrSMPHItbYVbJzrsGcgWnggvlkUWcAEFkujjBIRKPzuKouLoeBYteVVSCN";
    // *stdout << str;
    // *stdout << str.find("ncZPIPWeXtCqmusRohIqSNmldcUzmgmlUpDseKVFJVNOoUzYlKmCDidAQflfbJUZCLSzOhWGZCrzpYkWhHtBHHDszW"
    //                     "gPUmSXsBjobOKGTQxsTX"
    //                     "vZVyrDjDgHbbMYWZAwpvoSNvokuMZzNapXRlWKjwSEySQspoDfcLwLSRXOAvKRdnFGBHruDfOSNrLkeLAsZUtiIOtN"
    //                     "WBeOBapounIhnvPuPuSU"
    //                     "lkISvNxvMZUVGYsQXSYrAXjbPLRfskZZDLneLkCmQhBtDdNMDyOBrdBkdgCDcSqNCFLucEwjepnIhWyHaqoUoKOzUG"
    //                     "FyqglNiLdvdBEtBSqtZ"
    //                     "j");
}