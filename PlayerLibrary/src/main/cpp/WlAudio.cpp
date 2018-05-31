//
// Created by yuxin on 2018-05-31.
//

#include "WlAudio.h"

WlAudio::WlAudio(WlPlayStatus *playstatus) {
    this->playStatus = playstatus;
    queue = new WlQueue(playstatus);
}

WlAudio::~WlAudio() {

}
