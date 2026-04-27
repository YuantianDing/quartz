
#pragma once

#include "gate.h"
#include "utils/utils.h"
#include <math.h>

namespace quartz {
class THalf : public Gate {
 public:
  THalf()
      : Gate(GateType::thalf, 1 /*num_qubits*/, 0 /*num_parameters*/),
        mat({{ComplexType(1), ComplexType(0)},
        {ComplexType(0), ComplexType(cos_param(PI * ParamType(1, 8)) + 1.0i * sin_param(PI * ParamType(1, 8)))}}) {
      }
      
  MatrixBase *get_matrix() override { return &mat; }
  Matrix<2> mat;
};
class THalfDG : public Gate {
 public:
  THalfDG()
      : Gate(GateType::thalf_dg, 1 /*num_qubits*/, 0 /*num_parameters*/),
        mat({{ComplexType(1), ComplexType(0)},
        {ComplexType(0), ComplexType(cos_param(PI * ParamType(1, 8)) - 1.0i * sin_param(PI * ParamType(1, 8)))}}) {
      }
      
  MatrixBase *get_matrix() override { return &mat; }
  Matrix<2> mat;
};

class PhaseFracPI3 : public Gate {
 public:
  PhaseFracPI3()
      : Gate(GateType::phase_frac_pi_3, 1 /*num_qubits*/, 0 /*num_parameters*/),
        mat({{ComplexType(1), ComplexType(0)},
        {ComplexType(0), ComplexType(cos_param(PI * ParamType(1, 3)), sin_param(PI * ParamType(1, 3)))}}) {
      }
      
  MatrixBase *get_matrix() override { return &mat; }
  Matrix<2> mat;
};

class PhaseFracPI3DG : public Gate {
 public:
  PhaseFracPI3DG()
      : Gate(GateType::phase_frac_pi_3_dg, 1 /*num_qubits*/, 0 /*num_parameters*/),
        mat({{ComplexType(1), ComplexType(0)},
        {ComplexType(0), ComplexType(cos_param(PI * ParamType(1, 3)), -sin_param(PI * ParamType(1, 3)))}}) {
      }
      
  MatrixBase *get_matrix() override { return &mat; }
  Matrix<2> mat;
};
}  // namespace quartz
