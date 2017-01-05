#include "def.h"

void print_struct_definition(){
  printf("target triple = \"x86_64-unknown-linux-gnu\"\n");
  
  printf("%%struct.CarElt = type {\n");
  printf("	i32,\n");
  printf("	%%struct.tInitCar,\n");
  printf("	%%struct.tPublicCar,\n");
  printf("	%%struct.tCarRaceInfo,\n");
  printf("	%%struct.tPrivCar,\n");
  printf("	%%struct.tCarCtrl,\n");
  printf("	%%struct.tCarPitCmd,\n");
  printf("	%%struct.RobotItf*,\n");
  printf("	%%struct.CarElt*\n");
  printf("}\n");
  
  printf("%%struct.tInitCar = type {\n");
  printf("	[32 x i8],\n");
  printf("	[32 x i8],\n");
  printf("	[32 x i8],\n");
  printf("	[32 x i8],\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	[3 x float],\n");
  printf("	%%struct.t3Dd,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	[4 x %%struct.tWheelSpec],\n");
  printf("	%%struct.tVisualAttributes\n");
  printf("}\n");
  
  printf("%%struct.t3Dd = type {\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
  
  printf("%%struct.tWheelSpec = type {\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
  
  
  printf("%%struct.tVisualAttributes = type {\n");
  printf("	i32,\n");
  printf("	[2 x %%struct.t3Dd],\n");
  printf("	float\n");
  printf("}\n");
  
  
  printf("%%struct.tPublicCar = type {\n");
  printf("	%%struct.tDynPt,\n");
  printf("	%%struct.tDynPt,\n");
  printf("	[4 x [4 x float]],\n");
  printf("	%%struct.tTrkLocPos,\n");
  printf("	i32,\n");
  printf("	[4 x %%struct.tPosd]\n");
  printf("}\n");
  
  
  printf("%%struct.tDynPt = type {\n");
  printf("	%%struct.tPosd,\n");
  printf("	%%struct.tPosd,\n");
  printf("	%%struct.tPosd\n");
  printf("}\n");
  
  
  printf("%%struct.tPosd = type {\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.tTrkLocPos = type {\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.trackSeg = type {\n");
  printf("	i8*,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	[4 x %%struct.t3Dd],\n");
  printf("	[7 x float],\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	%%struct.SegExt*,\n");
  printf("	%%struct.trackSurface*,\n");
  printf("	[2 x %%struct.trackBarrier*],\n");
  printf("	%%struct.RoadCam*,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%union.anon.0\n");
  printf("}\n");
	
	
  printf("%%struct.SegExt = type {\n");
  printf("	i32,\n");
  printf("	i32*\n");
  printf("}\n");
	
	
  printf("%%struct.trackSurface = type {\n");
  printf("	%%struct.trackSurface*,\n");
  printf("	i8*,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.trackBarrier = type {\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	%%struct.trackSurface*,\n");
  printf("	%%class.v2t\n");
  printf("}\n");
	
	
  printf("%%class.v2t = type {\n");
  printf("	%%union.anon\n");
  printf("}\n");
	
	
  printf("%%union.anon = type {\n");
  printf("	%%struct.anon\n");
  printf("}\n");
	
	
  printf("%%struct.anon = type {\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.RoadCam = type {\n");
  printf("	i8*,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	%%struct.RoadCam*\n");
  printf("}\n");
	
	
  printf("%%union.anon.0 = type {\n");
  printf("	%%struct.anon.1\n");
  printf("}\n");
	
	
  printf("%%struct.anon.1 = type {\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.trackSeg*\n");
  printf("}\n");
	
	
  printf("%%struct.tCarRaceInfo = type {\n");
  printf("	double,\n");
  printf("	i8,\n");
  printf("	double,\n");
  printf("	double,\n");
  printf("	double,\n");
  printf("	double,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	double,\n");
  printf("	i32,\n");
  printf("	double,\n");
  printf("	double,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	double,\n");
  printf("	%%struct.TrackOwnPit*,\n");
  printf("	i32,\n");
  printf("	%%struct.CarPenaltyHead\n");
  printf("}\n");
	
	
  printf("%%struct.TrackOwnPit = type {\n");
  printf("	%%struct.tTrkLocPos,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	i32,\n");
  printf("	[4 x %%struct.CarElt*]\n");
  printf("}\n");
	
	
  printf("%%struct.CarPenaltyHead = type {\n");
  printf("	%%struct.CarPenalty*,\n");
  printf("	%%struct.CarPenalty**\n");
  printf("}\n");
	
	
  printf("%%struct.CarPenalty = type {\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	%%struct.anon.2\n");
  printf("}\n");
	
	
  printf("%%struct.anon.2 = type {\n");
  printf("	%%struct.CarPenalty*,\n");
  printf("	%%struct.CarPenalty**\n");
  printf("}\n");
	
	
  printf("%%struct.tPrivCar = type {\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i32,\n");
  printf("	[32 x i8],\n");
  printf("	[4 x %%struct.tWheelState],\n");
  printf("	[4 x %%struct.tPosd],\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	[10 x float],\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	[4 x float],\n");
  printf("	[4 x float],\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	%%struct.tCollisionState_\n");
  printf("}\n");
	
	
  printf("%%struct.tWheelState = type {\n");
  printf("	%%struct.tPosd,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	i32,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.tCollisionState_ = type {\n");
  printf("	i32,\n");
  printf("	[3 x float],\n");
  printf("	[3 x float]\n");
  printf("}\n");
	
	
  printf("%%struct.tCarCtrl = type {\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	[4 x [32 x i8]],\n");
  printf("	[4 x float],\n");
  printf("	i32\n");
  printf("}\n");
	
	
  printf("%%struct.tCarPitCmd = type {\n");
  printf("	float,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	%%struct.tCarPitSetup\n");
  printf("}\n");
	
	
  printf("%%struct.tCarPitSetup = type {\n");
  printf("	%%struct.tCarPitSetupValue,\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	%%struct.tCarPitSetupValue,\n");
  printf("	%%struct.tCarPitSetupValue,\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[4 x %%struct.tCarPitSetupValue],\n");
  printf("	[2 x %%struct.tCarPitSetupValue],\n");
  printf("	[2 x %%struct.tCarPitSetupValue],\n");
  printf("	[2 x %%struct.tCarPitSetupValue],\n");
  printf("	[2 x %%struct.tCarPitSetupValue],\n");
  printf("	[2 x %%struct.tCarPitSetupValue],\n");
  printf("	[8 x %%struct.tCarPitSetupValue],\n");
  printf("	[2 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x %%struct.tCarPitSetupValue],\n");
  printf("	[3 x i32]\n");
  printf("}\n");
	
	
  printf("%%struct.tCarPitSetupValue = type {\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.RobotItf = type {\n");
  printf("	void (i32, %%struct.tTrack*, i8*, i8**, %%struct.Situation*)*,\n");
  printf("	 {}*,\n");
  printf("	 {}*,\n");
  printf("	 {}*,\n");
  printf("	 i32 (i32, %%struct.CarElt*, %%struct.Situation*)*,\n");
  printf("	 void (i32)*,\n");
  printf("	 i32\n");
  printf("}\n");
	
	
  printf("%%struct.tTrack = type {\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	%%struct.tTrackPitInfo,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.trackSurface*,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	%%struct.t3Dd,\n");
  printf("	%%struct.tTrackGraphicInfo\n");
  printf("}\n");
	
	
  printf("%%struct.tTrackPitInfo = type {\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.trackSeg*,\n");
  printf("	%%struct.TrackOwnPit*,\n");
  printf("	i32,\n");
  printf("	i32\n");
  printf("}\n");
	
	
  printf("%%struct.tTrackGraphicInfo = type {\n");
  printf("	i8*,\n");
  printf("	i8*,\n");
  printf("	i32,\n");
  printf("	[3 x float],\n");
  printf("	i32,\n");
  printf("	i8**,\n");
  printf("	%%struct.tTurnMarksInfo\n");
  printf("}\n");
	
	
  printf("%%struct.tTurnMarksInfo = type {\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float,\n");
  printf("	float\n");
  printf("}\n");
	
	
  printf("%%struct.Situation = type {\n");
  printf("	%%struct.tRaceAdmInfo,\n");
  printf("	double,\n");
  printf("	double,\n");
  printf("	i32,\n");
  printf("	%%struct.CarElt**\n");
  printf("}\n");
	
	
  printf("%%struct.tRaceAdmInfo = type {\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i32,\n");
  printf("	i64\n");
  printf("}\n\n");
}

void print_drive_prototype(int offset){
  if(offset == DRIVE_BEGIN){
    printf("define void @drive(i32 %%index, %%struct.CarElt* %%car, %%struct.Situation* %%s) {\n");
    printf("\t%%ctrl           = getelementptr %%struct.CarElt* %%car, i32 0, i32 5\n");
    printf("\t%%public_car	= getelementptr %%struct.CarElt* %%car, i32 0, i32 2\n");
    printf("\t%%pos		= getelementptr %%struct.tPublicCar* %%public_car, i32 0, i32 3\n");
    printf("\t%%seg.addr	= getelementptr %%struct.tTrkLocPos* %%pos, i32 0, i32 0\n");
    printf("\t%%seg		= load %%struct.trackSeg** %%seg.addr\n\n");

    printf("\t%%steer		= getelementptr %%struct.tCarCtrl* %%ctrl, i32 0, i32 0\n");
    printf("\t%%accelCmd       = getelementptr %%struct.tCarCtrl* %%ctrl, i32 0, i32 1\n");
    printf("\t%%brakeCmd	= getelementptr %%struct.tCarCtrl* %%ctrl, i32 0, i32 2\n");
    printf("\t%%clutchCmd	= getelementptr %%struct.tCarCtrl* %%ctrl, i32 0, i32 3\n");
    printf("\t%%gear		= getelementptr %%struct.tCarCtrl* %%ctrl, i32 0, i32 4\n\n");
  }
  else{
    printf("\tret void\n");
    printf("}\n\n");
  }
  
}



void print_footer(){
  printf("declare float @norm_pi_pi(float %%a)\n");
  printf("declare float @get_track_angle(%%struct.tTrkLocPos*)\n");
  printf("declare float @get_pos_to_right(%%struct.tTrkLocPos*)\n");
  printf("declare float @get_pos_to_middle(%%struct.tTrkLocPos*)\n");
  printf("declare float @get_pos_to_left(%%struct.tTrkLocPos*)\n");
  printf("declare float @get_pos_to_start(%%struct.tTrkLocPos*)\n");
  printf("declare float @get_track_seg_length(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_width(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_start_width(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_end_width(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_radius(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_right_radius(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_left_radius(%%struct.trackSeg*)\n");
  printf("declare float @get_track_seg_arc(%%struct.trackSeg*)\n");
  printf("declare %%struct.trackSeg* @get_track_seg_next(%%struct.trackSeg*)\n");
  printf("declare float @get_car_yaw(%%struct.CarElt*)\n");
}