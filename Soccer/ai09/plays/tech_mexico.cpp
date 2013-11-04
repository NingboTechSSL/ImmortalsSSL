#include "ai09.h"

#include "helpers.h"

float tetta = 0;

void ai09::tech_mexico ( void )
{
	int rn = 0;
	ERRTSetObstacles ( rn , false , false , true , true );
	OwnRobot[rn].target.Angle = 90.0f;
	float hhh = sinDeg(tetta);
	float ggg = cosDeg(tetta);

	if ( hhh < 0 )
		hhh = -1;
	else
		hhh = 1;
	
	Navigate2Point ( rn   , Vec2 (  1500.00*hhh+00.0f , 1500+hhh*00.0f ) , 0 , 100 );
	//OwnRobot[rn].face(Vec2(0, 0));
	//ERRTNavigate2Point ( rn   , Vec2 ( -1600.0f * hhh , ggg*1600.0f ) , 0 , 100 );
	//OwnRobot[attack].MoveByMotion(Vec3(0, 30.0*sin(tetta*3.14/180.0), 0));
	
	//dribble(rn, Vec2(0, 0));
	
	ERRTSetObstacles ( rn+1 , true , false , true , true );
	OwnRobot[rn+1].target.Angle = 90.0f;
	ERRTNavigate2Point ( rn+1 , Vec2 ( -500.0f , 1800.0f*sin ( ( tetta + 30 ) * 3.1415 / 180.0 ) ) , 0 , 100 );

	ERRTSetObstacles ( rn+2 , true , false , true , true );
	OwnRobot[rn+2].target.Angle = 0.0f;
	//ERRTNavigate2Point ( rn+2 , Vec2 ( 0.0f , 1800.0f*sin ( ( tetta + 60 ) * 3.1415 / 180.0 ) ) , 0 , 100 );
	ERRTNavigate2Point ( rn+2   , Vec2 (  hhh*2700.0f , -1300.0f ) , 0 , 100 );


	ERRTSetObstacles ( rn+3 , true , false , true , true );
	OwnRobot[rn+3].target.Angle = 90.0f;
	ERRTNavigate2Point ( rn+3 , Vec2 ( 500.0f , 1800.0f*sin ( ( tetta + 90 ) * 3.1415 / 180.0 ) ) , 0 , 100 );

	ERRTSetObstacles ( rn+4 , true , false , true , true );
	OwnRobot[rn+4].target.Angle = 90.0f;
	ERRTNavigate2Point ( rn+4 , Vec2 ( 1000.0f , 1800.0f*sin ( ( tetta + 120 ) * 3.1415 / 180.0 ) ) , 0 , 100 );

	tetta +=1.0;

	if ( tetta >= 360 )
		tetta = 0;
}