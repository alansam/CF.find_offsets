//
//  findit.cpp
//  CF.find_offset
//
//  Created by Alan Sampson on 4/11/21.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "CF.find_offset\n"sv;
  std::cout << "C++ Version: "s << __cplusplus << std::endl;

  auto const playlist = std::vector {
    "addicted"sv, "battery"sv,  "cold"sv, "demons"sv,     "epic"sv,   "everlong"sv,
    "fuel"sv,     "given"sv,    "halo"sv, "immortals"sv,  "jaded"sv,  "jars"sv,
  };

  auto ans { 'N' };

  auto cc { 0ul };
  auto constexpr cc_max { 6ul };
  std::cout << "Playlist:\n"sv;
  std::for_each(playlist.cbegin(), playlist.cend(), [&cc](auto pl) {
    std::cout << std::setw(10) << pl
              << (++cc % cc_max == 0 ? "\n"sv : ""sv);
  });
  std::cout << '\n' << "playlist size: "sv << playlist.size() << '\n';

  auto songTitle { ""s };

  do {
    std::cout << "Enter a song title: \n"sv;
    std::getline(std::cin, songTitle);
    std::cout << std::endl;
    std::cout << "Searching for: "sv << std::quoted(songTitle) << '\n' << std::endl;
    auto const find_it = std::find(playlist.cbegin(), playlist.cend(), songTitle);

    if (find_it != playlist.cend()) {
      auto const element = std::distance(std::cbegin(playlist), find_it);
      std::cout << "Song "sv << std::quoted(songTitle) << " found. Element #: "sv
                << element + 1 << std::endl;
    }
    else {
      std::cout << "Song "sv << std::quoted(songTitle) << " not found."sv << std::endl;
    }

    std::cout << "Would you like to search again? \n"sv;
    std::cin >> ans;
    std::cin.ignore();
  } while (std::toupper(ans) == 'Y');

  return 0;
}
