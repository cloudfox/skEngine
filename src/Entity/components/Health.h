#pragma once


struct Health {
  Health() = default;
  Health(const Health&) = default;
  Health(float maxHP, float currentHP) : max(maxHP), current(currentHP) {}


  float Get() { return current; }
  float Set(float value) { current = value; }
  float Damage(float damage){ 
    current -= damage;
    if (current <= 0)
    {
      current = 0;
      // trigger death event
    }
    else if (current >= max)
      current = max;

  }



private:
  float max;
  float current;
};