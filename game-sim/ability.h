#ifndef ABILITY_H
#define ABILITY_H

static constexpr unsigned int ABILITY_ERROR_VALUE_ = 999;

enum SkillType
{
    CONTACT = 0,
    POWER,
    SPEED,
    FIELDING,
    VELOCITY,
    CONTROL,
    BREAK,
    STAMINA
};

class Ability
{
public:
    Ability()
    {
       contact_ = power_ = speed_ = fielding_ = velocity_ = control_ = break_ = stamina_ = 0;
    }
    ~Ability(){}

    void SetToBatterDefaults()
    {
        velocity_ = control_ = break_ = 10;
    }
    void SetToPitcherDefaults()
    {
        contact_ = power_ = speed_ = 10;
    }

    void SetContactRating(const unsigned int &rate) { contact_ = rate; }
    void SetPowerRating(const unsigned int &rate) { power_ = rate; }
    void SetSpeedRating(const unsigned int &rate) { speed_ = rate; }
    void SetFieldingRating(const unsigned int &rate) { fielding_ = rate; }
    void SetVelocityRating(const unsigned int &rate) { velocity_ = rate; }
    void SetControlRating(const unsigned int &rate) { control_ = rate; }
    void SetBreakRating(const unsigned int &rate) { break_ = rate; }
    void SetStaminaRating(const unsigned int &rate) { stamina_ = rate; }

    const unsigned int &GetContactRating() const { return contact_; }
    const unsigned int &GetPowerRating() const { return power_; }
    const unsigned int &GetSpeedRating() const { return speed_; }
    const unsigned int &GetFieldingRating() const { return fielding_; }
    const unsigned int &GetVelocityRating() const { return velocity_; }
    const unsigned int &GetControlRating() const { return control_; }
    const unsigned int &GetBreakRating() const { return break_; }
    const unsigned int &GetStaminaRating() const { return stamina_; }

private:
    unsigned int contact_;
    unsigned int power_;
    unsigned int speed_;
    unsigned int fielding_;
    unsigned int velocity_;
    unsigned int control_;
    unsigned int break_;
    unsigned int stamina_;
};

#endif // ABILITY_H
