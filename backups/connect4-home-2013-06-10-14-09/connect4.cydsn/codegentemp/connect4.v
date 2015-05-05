// ======================================================================
// connect4.v generated from TopDesign.cysch
// 06/10/2013 at 10:52
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC4A 2
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PANTHER 3
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4A 2
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_5B 4
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 4
`define CYDEV_CHIP_REVISION_USED 0
// CharLCD_v1_90(ConversionRoutines=true, CUSTOM0=0,E,8,8,8,E,0, CUSTOM1=0,A,A,4,4,4,0, CUSTOM2=0,E,A,E,8,8,0, CUSTOM3=0,E,A,C,A,A,0, CUSTOM4=0,E,8,C,8,E,0, CUSTOM5=0,E,8,E,2,E,0, CUSTOM6=0,E,8,E,2,E,0, CUSTOM7=0,4,4,4,0,4,0, CustomCharacterSet=0, TypeReplacementString=uint8, CY_COMPONENT_NAME=CharLCD_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=LCD, CY_INSTANCE_SHORT_NAME=LCD, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=LCD, )
module CharLCD_v1_90_0 ;



	wire [6:0] tmpOE__LCDPort_net;
	wire [6:0] tmpFB_6__LCDPort_net;
	wire [6:0] tmpIO_6__LCDPort_net;
	wire [0:0] tmpINTERRUPT_0__LCDPort_net;
	electrical [0:0] tmpSIOVREF__LCDPort_net;

	cy_psoc3_pins_v1_10
		#(.id("0b2c0681-329a-4bd1-8a51-c4d7a4e1fa91/ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(21'b110_110_110_110_110_110_110),
		  .ibuf_enabled(7'b1_1_1_1_1_1_1),
		  .init_dr_st(7'b0_0_0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(7'b1_1_1_1_1_1_1),
		  .input_sync_mode(7'b0_0_0_0_0_0_0),
		  .intr_mode(14'b00_00_00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(", , , , , , "),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(7'b0_0_0_0_0_0_0),
		  .oe_reset(0),
		  .oe_sync(7'b0_0_0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(7'b0_0_0_0_0_0_0),
		  .output_conn(7'b0_0_0_0_0_0_0),
		  .output_mode(7'b0_0_0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(7'b0_0_0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,,,"),
		  .pin_mode("OOOOOOO"),
		  .por_state(4),
		  .use_annotation(7'b0_0_0_0_0_0_0),
		  .sio_group_cnt(0),
		  .sio_hyst(7'b0_0_0_0_0_0_0),
		  .sio_ibuf(""),
		  .sio_info(14'b00_00_00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(7'b0_0_0_0_0_0_0),
		  .spanning(0),
		  .vtrip(14'b10_10_10_10_10_10_10),
		  .width(7))
		LCDPort
		 (.oe(tmpOE__LCDPort_net),
		  .y({7'b0}),
		  .fb({tmpFB_6__LCDPort_net[6:0]}),
		  .io({tmpIO_6__LCDPort_net[6:0]}),
		  .siovref(tmpSIOVREF__LCDPort_net),
		  .interrupt({tmpINTERRUPT_0__LCDPort_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LCDPort_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{7'b1111111} : {7'b1111111};



endmodule

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Comp_v2_0(Hysteresis=0, Pd_Override=0, Polarity=0, PSOC5A=false, Speed=0, Sync=1, CY_COMPONENT_NAME=Comp_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=CompCH0, CY_INSTANCE_SHORT_NAME=CompCH0, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=CapSense_CompCH0, )
module Comp_v2_0_1 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_1;


    assign Net_9 = ~Net_1;



endmodule

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// IDAC8_v2_0(Current=0, Data_Source=0, Hardware_Enable=true, IDAC_Range=4, IDAC_Speed=0, Initial_Value=0, Polarity=4, Strobe_Mode=0, CY_COMPONENT_NAME=IDAC8_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=IdacCH0, CY_INSTANCE_SHORT_NAME=IdacCH0, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=CapSense_IdacCH0, )
module IDAC8_v2_0_2 (
    iOut,
    data,
    strobe,
    en,
    ipolarity);
    inout       iOut;
    electrical  iOut;
    input      [7:0] data;
    input       strobe;
    input       en;
    input       ipolarity;

    parameter Data_Source = 0;
    parameter Initial_Value = 0;
    parameter Strobe_Mode = 0;

    electrical  Net_124;
          wire  Net_194;
          wire  Net_195;
          wire  Net_158;
          wire  Net_157;
          wire  Net_123;
          wire  Net_125;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_125),
        .idir(Net_158),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(Net_124),
        .iout(iOut),
        .ioff(Net_123),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;


    assign Net_157 = ~en;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_125));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_124));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_123 = Net_157;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_158 = Net_195;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_194));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_195));



endmodule

// Component: cy_vref_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`endif

// Component: CapSense_CSD_AMux_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_30\CapSense_CSD_AMux_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_30"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_AMux_v3_30\CapSense_CSD_AMux_v3_30.v"
`endif

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: CapSense_CSD_MeasureCh_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_30\CapSense_CSD_MeasureCh_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_30"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_MeasureCh_v3_30\CapSense_CSD_MeasureCh_v3_30.v"
`endif

// Component: CapSense_CSD_ClockGen_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_30\CapSense_CSD_ClockGen_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_30"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\CapSense_CSD_ClockGen_v3_30\CapSense_CSD_ClockGen_v3_30.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// CapSense_CSD_v3_30(AnalogSwitchDivider=11, ClockSource=2, ConnectInactiveSensors=0, CtlModeReplacementString=SyncCtrl, CurrentSource=1, EnableTuneHelper=false, EzI2CInstanceName=EZI2C, GuardSensorEnable=false, IdacRange=4, Implementation_CH0=1, Implementation_CH1=1, IntClockFrequency=12, LowBaselineReset=5, MaximumSensors=62, MultipleAnalogSwitchDivider=true, NegativeNoiseThreshold=20, NumberOfChannels=1, PrechargePolarity=3, PrescalerOptions=1, PrsOptions=2, RawDataFilterType=0, RbNumber_CH0=0, RbNumber_CH1=0, RemoveCH1=true, RemoveVrefTerm=false, ScanSpeed=7, SensorAutoReset=false, SensorNumber_CH0=7, SensorNumber_CH1=0, SensorNumberChannel0=7, SensorNumberChannel1=0, ShieldEnable=false, SignalSizeReplacementString=uint8, SnsAlias_CH0=<?xml version='1.0'?><PinAliases Version='1'><pin0>Button0__BTN</pin0><pin1>Button1__BTN</pin1><pin2>LinearSlider0_e0__LS</pin2><pin3>LinearSlider0_e1__LS</pin3><pin4>LinearSlider0_e2__LS</pin4><pin5>LinearSlider0_e3__LS</pin5><pin6>LinearSlider0_e4__LS</pin6></PinAliases>, SnsAlias_CH1=<?xml version="1.0" ?><PinAliases Version="1"><pin0>pin1_ch1</pin0></PinAliases>, TunerProperties=, TuningMethod=2, VrefOptions=0, VrefValue=64, WaterProofingEnabled=false, WidgetResolution=8, WidgetsData=<?xml version="1.0" encoding="utf-16"?> <CyWidgetsList xmlns:version="v1.00">   <ListMainTerminal>     <CyTerminal NameIndex="0" WidgetName="Button0__BTN" />     <CyTerminal NameIndex="0" WidgetName="Button1__BTN" />     <CyTerminal NameIndex="0" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="1" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="2" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="3" WidgetName="LinearSlider0__LS" />     <CyTerminal NameIndex="4" WidgetName="LinearSlider0__LS" />   </ListMainTerminal>   <ListButtons>     <CyButton Name="Button0" Type="Button" Channel="First" Count="1" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1">       <Location>         <X>2147483647</X>         <Y>2147483647</Y>       </Location>       <Properties>         <Hysteresis>10</Hysteresis>         <Debounce>5</Debounce>         <FingerThreshold>100</FingerThreshold>         <NoiseThreshold>20</NoiseThreshold>         <ScanResolution>_10</ScanResolution>       </Properties>     </CyButton>     <CyButton Name="Button1" Type="Button" Channel="First" Count="1" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1">       <Location>         <X>2147483647</X>         <Y>2147483647</Y>       </Location>       <Properties>         <Hysteresis>10</Hysteresis>         <Debounce>5</Debounce>         <FingerThreshold>100</FingerThreshold>         <NoiseThreshold>20</NoiseThreshold>         <ScanResolution>_10</ScanResolution>       </Properties>     </CyButton>   </ListButtons>   <ListMatrixButtons />   <ListTouchPads />   <ListSliders>     <CySlider Name="LinearSlider0" Type="SliderLinear" Channel="First" Count="5" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1" Diplexing="false" Resolution="127" FilterPropertiesPos="FirstOrderIIR0_75">       <Location>         <X>2147483647</X>         <Y>2147483647</Y>       </Location>       <Properties>         <Hysteresis>0</Hysteresis>         <Debounce>1</Debounce>         <FingerThreshold>100</FingerThreshold>         <NoiseThreshold>20</NoiseThreshold>         <ScanResolution>_10</ScanResolution>       </Properties>     </CySlider>   </ListSliders>   <GuardSensor Name="GuardSensor" Type="Button" Channel="First" Count="1" Angle="0" Fliped="false" Fliped2D="false" ScaleFactor="1">     <Location>       <X>2147483647</X>       <Y>2147483647</Y>     </Location>     <Properties>       <Hysteresis>10</Hysteresis>       <Debounce>5</Debounce>       <FingerThreshold>100</FingerThreshold>       <NoiseThreshold>20</NoiseThreshold>       <ScanResolution>_10</ScanResolution>     </Properties>   </GuardSensor>   <GuardSensorTerminal NameIndex="0" WidgetName="GuardSensor__GRD" />   <CyScanSlotsList>     <ListScanSlots>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="Button0__BTN">         <ListTerminalsNames>           <string>Button0__BTN</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="Button1__BTN">         <ListTerminalsNames>           <string>Button1__BTN</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e0__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e1__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e2__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e3__LS</string>         </ListTerminalsNames>       </CyScanSlot>       <CyScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="LinearSlider0__LS">         <ListTerminalsNames>           <string>LinearSlider0_e4__LS</string>         </ListTerminalsNames>       </CyScanSlot>     </ListScanSlots>     <GuardSensorScanSlot IDACSettings="200" Sensitivity="2" AnalogSwitchDivider="11" WidgetName="GuardSensor__GRD">       <ListTerminalsNames>         <string>GuardSensor__GRD</string>       </ListTerminalsNames>     </GuardSensorScanSlot>   </CyScanSlotsList> </CyWidgetsList>, CY_COMPONENT_NAME=CapSense_CSD_v3_30, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=CapSense, CY_INSTANCE_SHORT_NAME=CapSense, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=CapSense, )
module CapSense_CSD_v3_30_3 (
    clock,
    shield,
    vref,
    bclk);
    input       clock;
    output      shield;
    inout       vref;
    electrical  vref;
    output      bclk;


          wire  Cmp_CH1;
          wire  Ioff_CH1;
          wire  DigitalClk;
          wire  PreChargeClk;
          wire  ShieldSignal;
          wire  Ioff_CH0;
          wire  Cmp_CH0;
          wire  Net_410;
          wire  Net_465;
          wire [7:0] Net_466;
          wire  clk;
          wire  mrst;
          wire  Net_469;
          wire  Net_411;
          wire  Net_412;
          wire [7:0] Net_413;
          wire  Net_420;
          wire  Net_470;
          wire [7:0] Net_471;
          wire  Net_474;
          wire  Net_421;
          wire  Net_422;
          wire [7:0] Net_423;
          wire  Net_375;
          wire  Net_372;
          wire  Net_374;
          wire  Net_373;
          wire  Net_371;
          wire  Net_396;
          wire  Net_397;
    electrical  Net_424;
    electrical  Net_425;
    electrical  Net_426;
    electrical  Net_427;
    electrical  Net_428;
    electrical  Net_429;
          wire  Net_458;
          wire  Net_460;
          wire  Net_464;
    electrical  Net_2129;
    electrical  Net_2101;
    electrical  Net_1440;
    electrical  Net_2153;
    electrical  Net_2098;
    electrical  Net_2072;
    electrical  Net_2077;
    electrical  Net_2038;
    electrical  Net_2031;
    electrical  Net_1903;
    electrical  Net_2149;
    electrical  Net_2107;
    electrical  Net_1956;
    electrical  Net_1433;
    electrical  Net_2164;
    electrical  Net_1438;
    electrical [6:0] Net_1410;
    electrical  Net_1983;
    electrical  Net_1425;
    electrical  Net_1917;
    electrical  Net_282;
          wire  Net_1644;
          wire  Net_461;
          wire  Net_1603;
          wire  Net_1358;
          wire  Net_1350;

    cy_psoc3_csabuf_v1_0 BufCH0 (
        .vref(Net_2129),
        .vout(Net_2072),
        .vchan(Net_2149));

    Comp_v2_0_1 CompCH0 (
        .Vplus(Net_282),
        .CmpOut(Cmp_CH0),
        .Vminus(Net_1983),
        .clock(1'b0));

    IDAC8_v2_0_2 IdacCH0 (
        .strobe(1'b0),
        .data(8'b00000000),
        .iOut(Net_1425),
        .en(Ioff_CH0),
        .ipolarity(1'b0));
    defparam IdacCH0.Data_Source = 0;
    defparam IdacCH0.Initial_Value = 0;
    defparam IdacCH0.Strobe_Mode = 0;

	wire [0:0] tmpOE__CmodCH0_net;
	wire [0:0] tmpFB_0__CmodCH0_net;
	wire [0:0] tmpIO_0__CmodCH0_net;
	wire [0:0] tmpINTERRUPT_0__CmodCH0_net;
	electrical [0:0] tmpSIOVREF__CmodCH0_net;

	cy_psoc3_pins_v1_10
		#(.id("7b6ff45f-1189-4f40-a4e2-a0868ea4dca9/232398c5-3876-4e07-8f5b-7cd7657055e2"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("Cmod_CH0"),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		CmodCH0
		 (.oe(tmpOE__CmodCH0_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__CmodCH0_net[0:0]}),
		  .analog({Net_1917}),
		  .io({tmpIO_0__CmodCH0_net[0:0]}),
		  .siovref(tmpSIOVREF__CmodCH0_net),
		  .interrupt({tmpINTERRUPT_0__CmodCH0_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CmodCH0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PortCH0_net;

	cy_psoc3_port_v1_0
		#(.width(7),
		  .siorefwidth(4),
		  .id("7b6ff45f-1189-4f40-a4e2-a0868ea4dca9/dd9c1af8-be5a-4b9e-b10c-b2d9f11dc9fc"),
		  .pin_aliases({"Button0__BTN,But","ton1__BTN,Linear","Slider0_e0__LS,L","inearSlider0_e1_","_LS,LinearSlider","0_e2__LS,LinearS","lider0_e3__LS,Li","nearSlider0_e4__","LS"}),
		  .access_mode("HW_ONLY"),
		  .layout_mode("NONCONTIGUOUS"),
		  .port_mode("ANALOG"),
		  .intr_mode(14'b00000000000000),
		  .drive_mode(21'b100100100100100100100),
		  .por_state(0),
		  .enable_shielding(7'b0000000),
		  .cs_mode(2'b11))
		PortCH0
		 (.oe(tmpOE__PortCH0_net),
		  .y(7'b0),
		  .analog(Net_1410[6:0]),
		  .precharge(PreChargeClk));

	assign tmpOE__PortCH0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? 1'b1 : 1'b0;


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("89B398AD-36A8-4627-9212-707F2986319E"),
		  .name("1.024V"))
		VrefRefCH0
		 (.vout(Net_2038));


    // -- AMux AMuxCH0 start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMuxCH0(
        .muxin({
            Net_1425,
            Net_282,
            Net_1917,
            Net_1410[6],
            Net_1410[5],
            Net_1410[4],
            Net_1410[3],
            Net_1410[2],
            Net_1410[1],
            Net_1410[0]
            }),
        .vout(Net_2072)
        );
    
    defparam AMuxCH0.muxin_width = 10;
    defparam AMuxCH0.init_mux_sel = 10'h0;
    defparam AMuxCH0.one_active = 0;
    
    // -- AMux AMuxCH0 end --

	// Select_VrefCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Select_VrefCH0_connect(Net_1983, Net_2038);
	defparam Select_VrefCH0_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_375));

    CapSense_CSD_MeasureCh_v3_30 MeasureCH0 (
        .cmp_in(Cmp_CH0),
        .pulse(DigitalClk),
        .clock(clk),
        .ioff(Ioff_CH0),
        .interrupt(Net_1603),
        .reset(mrst),
        .start(Net_1350),
        .enable(Net_373));
    defparam MeasureCH0.IdacOptions = 1;
    defparam MeasureCH0.ImplementationType = 1;

    CapSense_CSD_ClockGen_v3_30 ClockGen (
        .clock(clk),
        .dpulse(DigitalClk),
        .ppulse(PreChargeClk),
        .start0(Net_1350),
        .mesrst(mrst),
        .start1(Net_1358),
        .enable(Net_371),
        .reset(Net_375),
        .shield(ShieldSignal));
    defparam ClockGen.IdacOptions = 1;
    defparam ClockGen.PrescalerOptions = 1;
    defparam ClockGen.PrsOptions = 2;

    OneTerminal OneTerminal_3 (
        .o(Net_374));

    OneTerminal OneTerminal_2 (
        .o(Net_373));


	cy_isr_v1_0
		#(.int_type(2'b00))
		IsrCH0
		 (.int_signal(Net_1603));


    OneTerminal OneTerminal_1 (
        .o(Net_371));

	// ClockSelect_VirtualMux (cy_virtualmux_v1_0)
	assign clk = Net_461;


	cy_clock_v1_0
		#(.id("7b6ff45f-1189-4f40-a4e2-a0868ea4dca9/a5cdd87b-17c1-4ba5-bfd2-c7548c5c7e2f"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		IntBusClock
		 (.clock_out(Net_461));


    cy_analog_noconnect_v1_0 NoConnect_VchanCH0 (
        .noconnect(Net_424));

	// Connect_VdacToAmuxCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Connect_VdacToAmuxCH0_connect(Net_1903, Net_425);
	defparam Connect_VdacToAmuxCH0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_1_024ToAMuxCH0 (
        .noconnect(Net_425));

	// Select_VrefOutput (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Select_VrefOutput_connect(vref, Net_2038);
	defparam Select_VrefOutput_connect.sig_width = 1;

	// Select_VrefCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Select_VrefCH1_connect(Net_2164, Net_2038);
	defparam Select_VrefCH1_connect.sig_width = 1;

	// Connect_VdacToAmuxCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 Connect_VdacToAmuxCH1_connect(Net_2107, Net_426);
	defparam Connect_VdacToAmuxCH1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_1_024ToAMuxCH1 (
        .noconnect(Net_426));

	// DisableCapSBuf_VrefCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VrefCH0_connect(Net_2129, Net_1983);
	defparam DisableCapSBuf_VrefCH0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_VrefCH0 (
        .noconnect(Net_427));

	// DisableCapSBuf_VchanCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VchanCH1_connect(Net_2153, Net_1956);
	defparam DisableCapSBuf_VchanCH1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_VchanCH1 (
        .noconnect(Net_428));

	// DisableCapSBuf_VrefCH1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VrefCH1_connect(Net_2098, Net_2164);
	defparam DisableCapSBuf_VrefCH1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 NoConnect_VrefCH1 (
        .noconnect(Net_429));

	// DisableCapSBuf_VchanCH0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 DisableCapSBuf_VchanCH0_connect(Net_2149, Net_1917);
	defparam DisableCapSBuf_VchanCH0_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_458));


    assign bclk = Net_460 | Net_458;


	cy_clock_v1_0
		#(.id("7b6ff45f-1189-4f40-a4e2-a0868ea4dca9/52b807b3-40a8-4a39-b1e7-e18f76c3b871"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_tmp
		 (.clock_out(Net_460));



    assign shield = ShieldSignal;


endmodule

// Timer_v2_50(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeviceFamily=PSoC5, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=false, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=0, NumberOfCaptures=1, param45=1, Period=65535, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=rstSts, RunMode=0, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=0, VerilogSectionReplacementString=sT16, CY_COMPONENT_NAME=Timer_v2_50, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Timer, CY_INSTANCE_SHORT_NAME=Timer, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Timer, )
module Timer_v2_50_4 (
    clock,
    reset,
    interrupt,
    enable,
    capture,
    trigger,
    capture_out,
    tc);
    input       clock;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       trigger;
    output      capture_out;
    output      tc;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 0;
    parameter Resolution = 16;
    parameter SiliconRevision = "0";

          wire  Net_260;
          wire  Net_261;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    cy_psoc3_timer_v1_0 TimerHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_266),
        .kill(Net_260),
        .clock(clock),
        .tc(Net_51),
        .compare(Net_261),
        .interrupt(Net_57));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_57;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_51;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// Component: B_UART_v2_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30\B_UART_v2_30.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_30\B_UART_v2_30.v"
`endif

// UART_v2_30(Address1=0, Address2=0, BaudRate=9600, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, CtrlModeReplacementString=SyncCtl, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=true, InternalClock=true, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=76800, RXAddressMode=0, RXBufferSize=4, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=4, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_COMPONENT_NAME=UART_v2_30, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=UART, )
module UART_v2_30_5 (
    rx_clk,
    rx_data,
    tx_clk,
    tx_data,
    rx_interrupt,
    tx_interrupt,
    tx,
    tx_en,
    rts_n,
    reset,
    cts_n,
    clock,
    rx);
    output      rx_clk;
    output      rx_data;
    output      tx_clk;
    output      tx_data;
    output      rx_interrupt;
    output      tx_interrupt;
    output      tx;
    output      tx_en;
    output      rts_n;
    input       reset;
    input       cts_n;
    input       clock;
    input       rx;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 1;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("13020833333.3333"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_30 BUART (
        .cts_n(cts_n),
        .tx(tx),
        .rts_n(rts_n),
        .tx_en(tx_en),
        .clock(Net_61),
        .reset(reset),
        .rx(rx),
        .tx_interrupt(tx_interrupt),
        .rx_interrupt(rx_interrupt),
        .tx_data(tx_data),
        .tx_clk(tx_clk),
        .rx_data(rx_data),
        .rx_clk(rx_clk));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 1;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 1;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 1;



endmodule

// top
module top ;

          wire  Net_290;
          wire  Net_289;
          wire  Net_288;
          wire  Net_287;
          wire  Net_286;
          wire  Net_285;
          wire  Net_284;
          wire  Net_283;
          wire  Net_282;
          wire  Net_281;
          wire  Net_314;
          wire  Net_228;
          wire  Net_10;
          wire  Net_489;
          wire  Net_488;
          wire  Net_487;
          wire  Net_486;
          wire  Net_485;
          wire  Net_12;
          wire  Net_199;
    electrical  Net_198;
          wire  Net_197;
          wire  Net_196;
          wire  Net_478;
          wire  Net_263;
          wire  Net_274;
          wire  Net_258;

    CharLCD_v1_90_0 LCD ();

    CapSense_CSD_v3_30_3 CapSense (
        .clock(1'b0),
        .shield(Net_197),
        .vref(Net_198),
        .bclk(Net_199));

    Timer_v2_50_4 Timer (
        .reset(Net_12),
        .interrupt(Net_485),
        .enable(1'b1),
        .trigger(1'b0),
        .capture(1'b0),
        .capture_out(Net_489),
        .tc(Net_478),
        .clock(Net_10));
    defparam Timer.CaptureCount = 2;
    defparam Timer.CaptureCounterEnabled = 0;
    defparam Timer.DeviceFamily = "PSoC5";
    defparam Timer.InterruptOnCapture = 0;
    defparam Timer.InterruptOnTC = 0;
    defparam Timer.Resolution = 16;
    defparam Timer.SiliconRevision = "0";


	cy_clock_v1_0
		#(.id("c0fb34bd-1044-4931-9788-16b01ce89812"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		timer_clock
		 (.clock_out(Net_10));


    ZeroTerminal ZeroTerminal_1 (
        .z(Net_12));


	cy_isr_v1_0
		#(.int_type(2'b10))
		Beam
		 (.int_signal(Net_478));


	wire [0:0] tmpOE__RemoteLED_net;
	wire [0:0] tmpFB_0__RemoteLED_net;
	wire [0:0] tmpIO_0__RemoteLED_net;
	wire [0:0] tmpINTERRUPT_0__RemoteLED_net;
	electrical [0:0] tmpSIOVREF__RemoteLED_net;

	cy_psoc3_pins_v1_10
		#(.id("72a1ef96-908b-4c9d-ab07-305b3196c5e2"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		RemoteLED
		 (.oe(tmpOE__RemoteLED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__RemoteLED_net[0:0]}),
		  .io({tmpIO_0__RemoteLED_net[0:0]}),
		  .siovref(tmpSIOVREF__RemoteLED_net),
		  .interrupt({tmpINTERRUPT_0__RemoteLED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RemoteLED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Connector_net;
	wire [0:0] tmpIO_0__Connector_net;
	wire [0:0] tmpINTERRUPT_0__Connector_net;
	electrical [0:0] tmpSIOVREF__Connector_net;

	cy_psoc3_pins_v1_10
		#(.id("913793fd-6444-4e37-8a1d-5270b61acf8e"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		Connector
		 (.oe(tmpOE__Connector_net),
		  .y({1'b0}),
		  .fb({Net_314}),
		  .io({tmpIO_0__Connector_net[0:0]}),
		  .siovref(tmpSIOVREF__Connector_net),
		  .interrupt({tmpINTERRUPT_0__Connector_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Connector_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    UART_v2_30_5 UART (
        .cts_n(1'b0),
        .tx(Net_258),
        .rts_n(Net_282),
        .tx_en(Net_283),
        .clock(1'b0),
        .reset(Net_274),
        .rx(Net_263),
        .tx_interrupt(Net_285),
        .rx_interrupt(Net_286),
        .tx_data(Net_287),
        .tx_clk(Net_288),
        .rx_data(Net_289),
        .rx_clk(Net_290));
    defparam UART.Address1 = 0;
    defparam UART.Address2 = 0;
    defparam UART.EnIntRXInterrupt = 0;
    defparam UART.EnIntTXInterrupt = 0;
    defparam UART.FlowControl = 0;
    defparam UART.HalfDuplexEn = 0;
    defparam UART.HwTXEnSignal = 1;
    defparam UART.NumDataBits = 8;
    defparam UART.NumStopBits = 1;
    defparam UART.ParityType = 0;
    defparam UART.RXEnable = 1;
    defparam UART.TXEnable = 1;

	wire [0:0] tmpOE__Din_net;
	wire [0:0] tmpIO_0__Din_net;
	wire [0:0] tmpINTERRUPT_0__Din_net;
	electrical [0:0] tmpSIOVREF__Din_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		Din
		 (.oe(tmpOE__Din_net),
		  .y({1'b0}),
		  .fb({Net_263}),
		  .io({tmpIO_0__Din_net[0:0]}),
		  .siovref(tmpSIOVREF__Din_net),
		  .interrupt({tmpINTERRUPT_0__Din_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Din_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Dout_net;
	wire [0:0] tmpFB_0__Dout_net;
	wire [0:0] tmpIO_0__Dout_net;
	wire [0:0] tmpINTERRUPT_0__Dout_net;
	electrical [0:0] tmpSIOVREF__Dout_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Dout
		 (.oe(tmpOE__Dout_net),
		  .y({Net_258}),
		  .fb({tmpFB_0__Dout_net[0:0]}),
		  .io({tmpIO_0__Dout_net[0:0]}),
		  .siovref(tmpSIOVREF__Dout_net),
		  .interrupt({tmpINTERRUPT_0__Dout_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dout_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_274));


	cy_isr_v1_0
		#(.int_type(2'b10))
		Location
		 (.int_signal(Net_314));


	wire [0:0] tmpOE__Colors_net;
	wire [0:0] tmpFB_0__Colors_net;
	wire [0:0] tmpIO_0__Colors_net;
	wire [0:0] tmpINTERRUPT_0__Colors_net;
	electrical [0:0] tmpSIOVREF__Colors_net;

	cy_psoc3_pins_v1_10
		#(.id("0af3a30a-6e67-42a1-9127-10db7e953825"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Colors
		 (.oe(tmpOE__Colors_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Colors_net[0:0]}),
		  .io({tmpIO_0__Colors_net[0:0]}),
		  .siovref(tmpSIOVREF__Colors_net),
		  .interrupt({tmpINTERRUPT_0__Colors_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Colors_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Column_net;
	wire [0:0] tmpFB_0__Column_net;
	wire [0:0] tmpIO_0__Column_net;
	wire [0:0] tmpINTERRUPT_0__Column_net;
	electrical [0:0] tmpSIOVREF__Column_net;

	cy_psoc3_pins_v1_10
		#(.id("5a755cc1-2285-40ca-bcff-df7c33c04be9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Column
		 (.oe(tmpOE__Column_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Column_net[0:0]}),
		  .io({tmpIO_0__Column_net[0:0]}),
		  .siovref(tmpSIOVREF__Column_net),
		  .interrupt({tmpINTERRUPT_0__Column_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Column_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Blue_net;
	wire [0:0] tmpFB_0__Blue_net;
	wire [0:0] tmpIO_0__Blue_net;
	wire [0:0] tmpINTERRUPT_0__Blue_net;
	electrical [0:0] tmpSIOVREF__Blue_net;

	cy_psoc3_pins_v1_10
		#(.id("07fd79a6-c4d9-47d2-a445-4e6be7fe56c7"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Blue
		 (.oe(tmpOE__Blue_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Blue_net[0:0]}),
		  .io({tmpIO_0__Blue_net[0:0]}),
		  .siovref(tmpSIOVREF__Blue_net),
		  .interrupt({tmpINTERRUPT_0__Blue_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Blue_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Green_net;
	wire [0:0] tmpFB_0__Green_net;
	wire [0:0] tmpIO_0__Green_net;
	wire [0:0] tmpINTERRUPT_0__Green_net;
	electrical [0:0] tmpSIOVREF__Green_net;

	cy_psoc3_pins_v1_10
		#(.id("60f21e57-8ad5-4a01-8e0c-1228e75e6e3d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Green
		 (.oe(tmpOE__Green_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Green_net[0:0]}),
		  .io({tmpIO_0__Green_net[0:0]}),
		  .siovref(tmpSIOVREF__Green_net),
		  .interrupt({tmpINTERRUPT_0__Green_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Green_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Red_net;
	wire [0:0] tmpFB_0__Red_net;
	wire [0:0] tmpIO_0__Red_net;
	wire [0:0] tmpINTERRUPT_0__Red_net;
	electrical [0:0] tmpSIOVREF__Red_net;

	cy_psoc3_pins_v1_10
		#(.id("acf0f641-7ad7-490d-86f1-ef20df05f4b1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Red
		 (.oe(tmpOE__Red_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Red_net[0:0]}),
		  .io({tmpIO_0__Red_net[0:0]}),
		  .siovref(tmpSIOVREF__Red_net),
		  .interrupt({tmpINTERRUPT_0__Red_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Red_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Row_net;
	wire [0:0] tmpFB_0__Row_net;
	wire [0:0] tmpIO_0__Row_net;
	wire [0:0] tmpINTERRUPT_0__Row_net;
	electrical [0:0] tmpSIOVREF__Row_net;

	cy_psoc3_pins_v1_10
		#(.id("52f31aa9-2f0a-497d-9a1f-1424095e13e6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Row
		 (.oe(tmpOE__Row_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Row_net[0:0]}),
		  .io({tmpIO_0__Row_net[0:0]}),
		  .siovref(tmpSIOVREF__Row_net),
		  .interrupt({tmpINTERRUPT_0__Row_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Row_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Update_net;
	wire [0:0] tmpFB_0__Update_net;
	wire [0:0] tmpIO_0__Update_net;
	wire [0:0] tmpINTERRUPT_0__Update_net;
	electrical [0:0] tmpSIOVREF__Update_net;

	cy_psoc3_pins_v1_10
		#(.id("ca3a9779-e160-4df0-8204-0ad01446052b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Update
		 (.oe(tmpOE__Update_net),
		  .y({Net_478}),
		  .fb({tmpFB_0__Update_net[0:0]}),
		  .io({tmpIO_0__Update_net[0:0]}),
		  .siovref(tmpSIOVREF__Update_net),
		  .interrupt({tmpINTERRUPT_0__Update_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Update_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

