#ifndef ZONE_H
#define ZONE_H

#include "../IDA/types.h"
#include "World.h"
#include "Field.h"
#include "../gfx/Chunk.h"
#include "../common/Vector2.h"
#include "../common/Vector3.h"
#include "Block.h"
#include "SpawnPoint.h"
#include <list>

namespace cube {
class Zone {
    public:

        enum RegionType: int
        {
            Plains = 0,
            Ocean = 1,
            Hills = 2,
            Woodlands = 3,
            Jungle = 4,
            Darkwoods = 5,
            SnowForest = 6,
            Mountains = 7,
            Wetlands = 8,
            Desert = 9,
            Savannah = 0x0A,
            Snowlands = 0x0B,
            Deadlands = 0x0C,
            Firelands = 0x0D,
        };

        virtual ~Zone();

        cube::World* world;
        IntVector2 position;
        _BYTE gap18[72];
        char some_struct;
        _BYTE gap61[351];
        gfx::Chunk chunk;
        _BYTE gap448[56];
        std::list<void*> some_list;
        int field_490;
        int field_494;
        std::list<void*> some_list_2;
        _BYTE gap4A8[112];
        cube::Field fields[4096];


        // Methods
        static IntVector2 ZoneCoordsFromDots(LongVector3 position);
        static IntVector2 ZoneCoordsFromBlocks(int64_t x, int64_t y);
        void SetBlock(IntVector3 zone_position, cube::Block block, bool update=true);
        cube::Block* GetBlock(IntVector3 zone_position);
        cube::Block GetBlockInterpolated(IntVector3 zone_position);

        LongVector3* GetWorldPosition(LongVector3* result, int x, int y);
        LongVector3* GetWorldPosition(LongVector3* result, int x, int y, int z);

        bool IsPositionFree(int x, int y, int z);

        void AddSpawnPoint(cube::SpawnPoint* spawnPoint);
    };
}

static_assert(sizeof(cube::Zone) == 0x58518, "cube::Zone is not the correct size.");

#endif // ZONE_H
