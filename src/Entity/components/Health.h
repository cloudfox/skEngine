#pragma once
/*!*****************************************************************************
\file     Health.h
\author   Steven Kugies
\par      www.skugies.com
\par      skugies.dev@gmail
*******************************************************************************/


struct Health {
  Health() = default;
  Health(const Health&) = default;
  Health(float maxHP, float currentHP) : max(maxHP), current(currentHP) {}


  float Get() { return current; }

  //Directly Set Value bypassing regular checks
  float Set(float value) { current = value; }

  //Modify Health with bounds checks, 
  // Note: armor/other calculations must be applied before this function is called
  void Damage(float damage){ 
    current -= damage;
    if (current <= 0)
    {
      current = 0;
      //TODO: trigger death event
    }
    else if (current >= max)
      current = max;
  }

private:
  float max;
  float current;
};