#include "stormdrop.h"

uint32_t stormdrop(uint32_t *state, uint32_t entropy) {
  entropy += entropy << 16;
  state[0] += state[1] ^ entropy;
  state[1]++;
  state[2] ^= entropy;
  entropy += entropy << 6;
  state[3] += state[2] ^ entropy;
  entropy ^= state[0] ^ (entropy >> 9);
  return state[3] ^ entropy;
}
