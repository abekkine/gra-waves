#ifndef WAVE_H
#define WAVE_H

#include <vector>
#include <Vector.h>
#include <Body.h>

class Wave
{
public:
    Wave();
    // DONE : Instead of center, use [body] reference to create wave instance.
    Wave( Body* body );
    // DONE : Wave initialization will be performed in universe, so change method below to void.
    // DONE : All Update methods should accept [double timeStep] as parameter.
    void Update( double timeStep );
    ~Wave();
    // DONE : Method [IsAlive] will be added to check wave status.
    bool IsAlive();
    Vector& GetCenter();
    bool Covers( Body *body );
    unsigned int Source();
    float *GetColor();
    Scalar Age();
    Scalar Mass();
    Scalar Radius();
    void SetColor( unsigned int color );
    void ResetColor();

public:
    static Scalar WAVE_LIFETIME;
    static Scalar WAVE_SPEED;
    static unsigned int WAVE_DEFAULTCOLOR;
    static Scalar WAVE_ALPHAFACTOR;
private:
    // DONE : Constant [conLifetime] added to keep track of wave lifetime.
    const Scalar conLifetime;
    const Scalar conSpeed;
    const Scalar conAlpha;
    const unsigned int conDefaultColor;
    // DONE : Member [alive] should be added to indicate wave is active.
    bool alive;
    // DONE : Rename 'id' as [source] to indicate inducing [body] id.
    unsigned int source;
    // DONE : Rename 'frame' to [age], used as sim_time.
    Scalar age;
    Scalar radius;
    Scalar mass;
    Vector center;
    // Separate coloring for waves.
    bool fColorEnable;
    float defaultColor[4];
    float waveColor[4];   
    float *activeColorPointer;

    void initVars();
    void convertColor( unsigned int color, float *color_array, bool alpha=false );
    
};

typedef std::vector< Wave * > WaveVectorType;

#endif

