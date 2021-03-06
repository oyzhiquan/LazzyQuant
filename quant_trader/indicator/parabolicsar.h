#ifndef PARABOLICSAR_H
#define PARABOLICSAR_H

#include "mql5_indicator.h"

class ParabolicSAR : public MQL5Indicator
{
    Q_OBJECT
    Q_CLASSINFO("parameter_number", "2")
    Q_PROPERTY(double SARStep MEMBER InpSARStep CONSTANT)
    Q_PROPERTY(double SARMaximum MEMBER InpSARMaximum CONSTANT)

public:
    Q_INVOKABLE explicit ParabolicSAR(double SARStep = 0.02, double SARMaximum = 0.2, QObject *parent = 0);

    void OnInit() override;

protected:
    const double InpSARStep;
    const double InpSARMaximum;

    IndicatorBuffer<double> ExtSARBuffer;
    IndicatorBuffer<double> ExtEPBuffer;
    IndicatorBuffer<double> ExtAFBuffer;

    int    ExtLastRevPos;
    bool   ExtDirectionLong;
    double ExtSarStep;
    double ExtSarMaximum;

    int OnCalculate (const int rates_total,                     // size of input time series
                     const int prev_calculated,                 // bars handled in previous call
                     const _TimeSeries<qint64>& time,           // Time
                     const _TimeSeries<double>& open,           // Open
                     const _TimeSeries<double>& high,           // High
                     const _TimeSeries<double>& low,            // Low
                     const _TimeSeries<double>& close,          // Close
                     const _TimeSeries<qint64>& tick_volume,    // Tick Volume
                     const _TimeSeries<qint64>& volume,         // Real Volume
                     const _TimeSeries<int>& spread             // Spread
                     ) override;
    double GetHigh(int nPosition,int nStartPeriod,const _TimeSeries<double> &HiData);
    double GetLow(int nPosition,int nStartPeriod,const _TimeSeries<double> &LoData);

signals:

public slots:
};

#endif // PARABOLICSAR_H
