#ifndef PROPOGATOR_HH
#define PROPOGATOR_HH

#include <math.h>
#include "TComplex.h"
#include "data_obj.h"

using namespace std;

class CPUWaveFunc : public DataObject {

    public:
        //CPUWaveFunc() {};
        CPUWaveFunc(TString dat_file_name, DPFPWAPoint *pwa_point)
            : DataObject(dat_file_name, pwa_point)
        {
            parameters_vector_resize();
            cpu_convert_mcp_to_pwa_paras();
            //            convert_mcp_to_pwa_paras();
            //        if (!check_integraty()) {
            //            cout << "test integraty fail!!!!" << endl;
            //            exit(1);
            //
            //        }
        };
        CPUWaveFunc(TString dat_file_name, TString weight_file_name, DPFPWAPoint *pwa_point)
            : DataObject(dat_file_name, weight_file_name, pwa_point)
        {
            parameters_vector_resize();
            convert_mcp_to_pwa_paras();
        };

        virtual ~CPUWaveFunc() {}
        void parameters_vector_resize();
        void cpu_convert_mcp_to_pwa_paras();
        double cpu_calculate0p(int);
        void convert_mcp_to_pwa_paras();
        bool check_integraty();
        double cpu_calEva(const vector<double> &, vector<double> &, int);
        void cpu_resize_intermediate_variables(int);


        TComplex cro(
                double,
                double,
                double) const;
        TComplex propogator980(
                double,
                double,
                double,
                double) const;
        TComplex pip(
                double) const;
        TComplex propogator600(
                double,
                double,
                double,
                double,
                double,
                double,
                double) const;
        TComplex propogator(
                double,
                double,
                double) const;
        TComplex propogator1270(
                double,
                double,
                double) const;

        void cpu_propogator(
                double,
                double,
                vector<TComplex> &,
                const vector<double>&,
                int);
        void cpu_propogator980(
                double,
                double,
                double,
                vector<TComplex> &,
                const vector<double>&,
                int);
        void cpu_propogator600(
                double,
                double,
                double,
                double,
                double,
                double,
                vector<TComplex> &,
                const vector<double>&,
                int);
        void cpu_propogator1270(
                double,
                double,
                vector<TComplex> &,
                const vector<double>&,
                int);

        void cpu_cast_spin11(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<vector<double> > &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin12(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin13(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin14(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin111(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin191(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin192(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin1(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin2(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin21(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin22(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin23(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin24(
                vector<vector<TComplex> > &fCF,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);
        void cpu_cast_spin25(
                vector<vector<TComplex> > &,
                const vector<TComplex> &,
                const vector<double> &,
                const vector<double> &,
                const vector<vector<double> > &,
                int);

        std::vector<PWA_PARAS> pwa_paras() const { return pwa_paras_; }


    private:
        std::vector<PWA_PARAS> pwa_paras_; // 利用四动量转换而来的中间变量

        vector<vector<double> > wu,w0p22,ak23w,w2p2,w2p1;
        vector<vector<double> > w2p3,w2p4,w2p5;
        vector<double> b2qf2xx,b4qjvf2,b2qjv2,b2qjv3,b2qbv2,b2qbv3,b1qjv2,b1qjv3,b1qbv2,b1qbv3,b1q2r23;
        vector<double> sv,s23,sv2,sv3;
        vector<vector<double> > wpf22;
        vector<double> b2qjvf2;
        vector<vector<double> > w1p12_1,w1p13_1,w1p12_2,w1p13_2;
        vector<vector<double> > w1p12_3,w1p13_3,w1p12_4,w1p13_4;
        vector<vector<double> > w1m12,w1m13;


        vector<TComplex> fCP;
        vector<vector<TComplex> > crp1, crp11;
        vector<vector<vector<TComplex> > > fCF;

};

#endif