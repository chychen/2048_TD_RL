#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdarg>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "2048.h"

class experience
{
  public:
    state sp;
    state spp;
};

class AI
{
  public:
    static void load_tuple_weights()
    {
        std::string filename = "0556623.weight"; // put the name of weight file here
        std::ifstream in;
        in.open(filename.c_str(), std::ios::in | std::ios::binary);
        if (in.is_open())
        {
            for (size_t i = 0; i < feature::list().size(); i++)
            {
                in >> *(feature::list()[i]);
                std::cout << feature::list()[i]->name() << " is loaded from " << filename << std::endl;
            }
            in.close();
        }
    }

    static void set_tuples()
	{
		//-------------TO DO--------------------------------
		// set tuple features
		// example: feature::list().push_back(new pattern<4>(0, 1, 2, 3));
		//--------------------------------------------------
		// origin about 97.51% (1000k)
		feature::list().push_back(new pattern<4>(0, 4, 8, 12));
		feature::list().push_back(new pattern<4>(1, 5, 9, 13));
		feature::list().push_back(new pattern<6>(0, 1, 4, 5, 8, 12));
		feature::list().push_back(new pattern<6>(1, 2, 5, 6, 9, 13));
		// new1 about 50% (100k)
		// feature::list().push_back(new pattern<7>(0, 1, 2, 3, 4, 5, 6));
		// feature::list().push_back(new pattern<7>(8, 9, 10, 11, 12, 13, 14));
		// feature::list().push_back(new pattern<7>(0, 1, 4, 5, 8, 9, 12));
		// feature::list().push_back(new pattern<7>(2, 3, 6, 7, 10, 11, 14));
		// new2 about 95% (100k)
		// feature::list().push_back(new pattern<4>(0, 1, 2, 3));
		// feature::list().push_back(new pattern<4>(4, 5, 6, 7));
		// feature::list().push_back(new pattern<6>(0, 1, 4, 5, 8, 12));
		// feature::list().push_back(new pattern<6>(1, 2, 5, 6, 9, 13));
		// new3
		// feature::list().push_back(new pattern<4>(0, 1, 4, 5));
		// feature::list().push_back(new pattern<4>(8, 9, 12, 13));
		// feature::list().push_back(new pattern<6>(0, 1, 4, 5, 8, 12));
		// feature::list().push_back(new pattern<6>(1, 2, 5, 6, 9, 13));
		// new4
		// feature::list().push_back(new pattern<6>(0, 1, 4, 5, 8, 9));
		// feature::list().push_back(new pattern<6>(1, 2, 5, 6, 9, 10));
		// feature::list().push_back(new pattern<6>(0, 1, 4, 5, 8, 12));
		// feature::list().push_back(new pattern<6>(1, 2, 5, 6, 9, 13));
		// new5
		// feature::list().push_back(new pattern<4>(0, 1, 2, 3));
		// feature::list().push_back(new pattern<4>(4, 5, 6, 7));
		// feature::list().push_back(new pattern<4>(8, 9, 10, 11));
		// feature::list().push_back(new pattern<4>(12, 13, 14, 15));
		// feature::list().push_back(new pattern<4>(0, 4, 8, 12));
		// feature::list().push_back(new pattern<4>(1, 5, 9, 13));
		// feature::list().push_back(new pattern<4>(2, 6, 10, 14));
		// feature::list().push_back(new pattern<4>(3, 7, 11, 15));
	}

    static int get_best_move(state s)
    { // return best move dir
        // note: check the returned value of move() != -1 (invalid move)
        //-------------TO DO--------------------------------
        float bestV = 0.0;
        int bestDir = 0;
        for (int nextDir = 0; nextDir < 4; nextDir++)
        { // four directions
            state tempState = s;
            float temp;
            if (tempState.move(nextDir) == -1)
                continue;
            temp = tempState.evaluate_score() + tempState.get_reward();
            if (temp > bestV)
            {
                bestV = temp;
                bestDir = nextDir;
            }
        }
        return bestDir;
        //--------------------------------------------------
    }
};