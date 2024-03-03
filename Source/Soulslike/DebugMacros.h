#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE_RED(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.0f, 12, FColor::Red, true);
#define DRAW_SPHERE_BLUE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.0f, 12, FColor::Blue, true);
#define DRAW_BOX(Center, Extent) if (GetWorld()) DrawDebugBox(GetWorld(), Center, Extent, FColor::Green, true);
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.0f, 0, 1.0f);
#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.0f, FColor::Red, true);
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
		{ \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.0f, 0, 1.0f); \
			DrawDebugPoint(GetWorld(), EndLocation, 15.0f, FColor::Red, true); \
		}