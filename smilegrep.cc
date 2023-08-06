#include "smiley/smiley.h"
#include <cxxopts.hpp>
#include <array>
#include <iostream>
#include <numeric>
#include <iterator>

class CountCallback : Smiley::CallbackBase {
  std::array<int, 256> elemCounts;
  int totCharge = 0;
  int numAromatic = 0;
  int numHeavy = 0;
  int numHetero = 0;
  int numUnknown = 0;
  void addAtom(int element, bool aromatic, int isotope, int hCount, int charge, int atomClass) {
    // invoked when an atom is completely parsed

    // element: 0, 1, 2, ... (0 is '*' in SMILES)
    // aromatic: true if the atom was lower case c, n, ...
    // isotope: -1, 0, 1, 2, 3, 4 ... (-1 means no isotope specified and is not the same as 0)
    // hCount: -1, 0, 1, 2, ..., 9 (-1 means default valence and is only for unbracketed atoms)
    // charge: -9, -8, ..., -1, 0, 1, ..., 8, 9
    // atomClass: 0, 1, 2, 3, 4, ... (0 means no atom class, specified atom classes should start from 1)
    elemCounts.at(element) += 1;
    totCharge += charge;
    if(aromatic) {
      numAromatic++;
    }
    if(element > 1) {
      numHeavy++;
    }
    if(element == 0) {
      numUnknown++;
    }
    if(element > 1 && element != 6) {
      numHetero++;
    }
  }



  void reset() {
    elemCounts.fill(0);
    totCharge = 0;
    numAromatic = 0;
    numHeavy = 0;
    numHetero = 0;
    numUnknown = 0;
  }
};

int main(int argc, char **argv) {
  cxxopts::Options options("smilegrep", "lightweight greplike tool for cheminformatics");
  options.add_options()
    ("h,help", "Print usage")
    ("filename", "Filename", cxxopts::value<std::string>())
    ;

  options.positional_help("[FILE]...");
  options.allow_unrecognised_options();
  auto result = options.parse(argc, argv);


  if(result.count("help")) {
   std::cout << options.help() << "\n";
   exit(0);
 }
 
  std::cout << options.help() << "\n";

  for(const auto& res : result.unmatched()) {
    std::cout << "got FILE " << res << "\n";
  }




  return 0;
}
