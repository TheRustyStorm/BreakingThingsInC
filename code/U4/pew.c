#include <stdio.h>
#include <stdint.h>

typedef struct{
  uint32_t ammo;
  uint32_t current_ammo_in_clip;
  uint32_t max_ammo_in_clip;
  uint32_t damage;
} Gun;

int remainingReloads(Gun g){
  return (int)(g.ammo / g.max_ammo_in_clip);
}

Gun reload(Gun g){
  if(g.max_ammo_in_clip == g.current_ammo_in_clip){
    return g;
  }
  int difference = g.max_ammo_in_clip - g.current_ammo_in_clip;
  if(g.ammo <= difference){
    difference = g.ammo;
  }
  g.ammo -= difference;
  g.current_ammo_in_clip += difference;
  printf("Reloading!\n");
  return g;
}

void pew(Gun* g){
  if(g->current_ammo_in_clip > 0){
    g->current_ammo_in_clip --;
    printf("%i damage done\n",g->damage);
  }else{
    *g = reload(*g);
  }
}


int main(){
  Gun g = {100, 19, 20, 10};
  printf("%i remaining reloads\n", remainingReloads(g));
  g = reload(g);
  printf("%i ammo in clip\n", g.current_ammo_in_clip);
  for(int i = 0; i < 3; i++){
    pew(&g);
    g = reload(g);
    printf("%u ammo in clip\n", g.current_ammo_in_clip);
    printf("%u ammo total\n", g.ammo);
  }
  return 0;
}
