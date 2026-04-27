#include "gen_ecc_set.h"

#include "gate/gate_utils.h"
#include "quartz/context/context.h"
#include "quartz/generator/generator.h"

#include <chrono>
#include <fstream>

using namespace quartz;

int main() {
  // gen_ecc_set({GateType::u1, GateType::u2, GateType::u3, GateType::cx,
  //              GateType::add},
  //             "IBM_3_3_", true, 3, 4, 3);
  // gen_ecc_set({GateType::h, GateType::cz},
  //             kQuartzRootPath.string() + "/eccset/H_CZ_2_2_", true, false, 2, 0,
  //             2);
  // for (int n = 5; n <= 8; n++) {
  //   std::string file_prefix = "Rigetti_";
  //   file_prefix += std::to_string(n);
  //   file_prefix += "_3_";
  //   gen_ecc_set({GateType::rx, GateType::rz, GateType::cz, GateType::add},
  //               file_prefix, true, 3, 2, n);
  // }
  // gen_ecc_set({GateType::u1, GateType::u2, GateType::u3, GateType::cx,
  //              GateType::add},
  //             "IBM_4_3_", true, 3, 4, 4);
  for (int i = 2; i <= 7; i++) {
    auto start = std::chrono::high_resolution_clock::now();
    gen_ecc_set({GateType::t, GateType::tdg, GateType::h, GateType::x, GateType::cx},
      kQuartzRootPath.string() + "/eccset/clifford-t-5", true, false,
      5, 0, i);
      auto end = std::chrono::high_resolution_clock::now();
      std::cout << "------------------ clifford-t-5: " << i << " " << std::chrono::duration<double>(end - start).count() << "s\n";
  }
  {
  auto start = std::chrono::high_resolution_clock::now();
  gen_ecc_set({GateType::s, GateType::sdg, GateType::h, GateType::x, GateType::cx},
    kQuartzRootPath.string() + "/eccset/clifford-5", true, false,
    3, 0, 7);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "clifford-5: " << std::chrono::duration<double>(end - start).count() << "s\n";
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
  gen_ecc_set({GateType::x, GateType::cx},
    kQuartzRootPath.string() + "/eccset/classic-5", true, false,
    3, 0, 7);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "classic-5-5: " << std::chrono::duration<double>(end - start).count() << "s\n";
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
  gen_ecc_set({
    GateType::y, GateType::z, GateType::cy, GateType::cz,
      GateType::s, GateType::sdg, GateType::t, GateType::tdg, GateType::h, GateType::x, GateType::cx},
              kQuartzRootPath.string() + "/eccset/common-clifford-t-5", true, false,
              3, 0, 6);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "common-clifford-t-5: " << std::chrono::duration<double>(end - start).count() << "s\n";
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
  gen_ecc_set({
      GateType::s, GateType::sdg, GateType::thalf, GateType::thalf_dg, GateType::h, GateType::x, GateType::cx},
              kQuartzRootPath.string() + "/eccset/clifford-t1-2", true, false,
              3, 0, 6);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "clifford-t1/2: " << std::chrono::duration<double>(end - start).count() << "s\n";
  }

  {
    auto start = std::chrono::high_resolution_clock::now();
    gen_ecc_set({
      GateType::s, GateType::sdg, GateType::phase_frac_pi_3, GateType::phase_frac_pi_3_dg, GateType::h, GateType::x, GateType::cx, GateType::input_qubit},
              kQuartzRootPath.string() + "/eccset/clifford-rz-pi-3", true, false,
              3, 0, 6);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "clifford-rz(pi/3): " << std::chrono::duration<double>(end - start).count() << "s\n";
  }
  return 0;
}
