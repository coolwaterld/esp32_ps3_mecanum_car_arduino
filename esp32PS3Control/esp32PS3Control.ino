#include <Ps3Controller.h>

int player = 0;
int battery = 0;

#define THRESHOLD_POS 100
#define THRESHOLD_NEG -100
#define THRESHOLD_ABS 5

void motor_forward(int motorID)
{
    // Serial.print(motorID);
    // Serial.println(" motor_forward");
    switch (motorID)
    {
    case 2:
        analogWrite(27, 255);
        analogWrite(13, 0);
        break;
    case 4:
        analogWrite(4, 255);
        analogWrite(2, 0);
        break;
    case 1:
        analogWrite(17, 0);
        analogWrite(12, 255);
        break;
    case 3:
        analogWrite(15, 0);
        analogWrite(14, 255);
        break;
    default:
        Serial.println("Wrong motorID");
    }
}
void motor_backward(int motorID)
{
    // Serial.print(motorID);
    // Serial.println(" motor_backward");
    switch (motorID)
    {
    case 2:
        analogWrite(27, 0);
        analogWrite(13, 255);
        break;
    case 4:
        analogWrite(4, 0);
        analogWrite(2, 255);
        break;
    case 1:
        analogWrite(17, 255);
        analogWrite(12, 0);
        break;
    case 3:
        analogWrite(15, 255);
        analogWrite(14, 0);
        break;
    default:
        Serial.println("Wrong motorID");
    }
}
void motor_stop(int motorID)
{
    // Serial.print(motorID);
    // Serial.println(" motor_stop");
    switch (motorID)
    {
    case 2:
        analogWrite(27, 0);
        analogWrite(13, 0);
        break;
    case 4:
        analogWrite(4, 0);
        analogWrite(2, 0);
        break;
    case 1:
        analogWrite(17, 0);
        analogWrite(12, 0);
        break;
    case 3:
        analogWrite(15, 0);
        analogWrite(14, 0);
        break;
    default:
        Serial.println("Wrong motorID");
    }
}

// Mecanum Wheel
// 1(/)------2(\)
// |      |
// 3(\)------4(/)

void mw_forward()
{
    Serial.println("mw_forward");
    motor_forward(1);
    motor_forward(2);
    motor_forward(3);
    motor_forward(4);
}
void mw_backward()
{
    Serial.println("mw_backward");
    motor_backward(1);
    motor_backward(2);
    motor_backward(3);
    motor_backward(4);
}
void mw_left()
{
    Serial.println("mw_left");
    motor_forward(1);
    motor_backward(2);
    motor_backward(3);
    motor_forward(4);

}
void mw_right()
{
    Serial.println("mw_right");
    motor_backward(1);
    motor_forward(2);
    motor_forward(3);
    motor_backward(4);
}
void mw_forward_left()
{
    Serial.println("mw_forward_left");
    // motor_stop(1);
    // motor_forward(2);
    // motor_forward(3);
    // motor_stop(4);
}
void mw_forward_right()
{
    Serial.println("mw_forward_right");
    // motor_forward(1);
    // motor_stop(2);
    // motor_stop(3);
    // motor_forward(4);
}
void mw_backward_left()
{
    Serial.println("mw_backward_left");
    // motor_backward(1);
    // motor_stop(2);
    // motor_stop(3);
    // motor_backward(4);
}
void mw_backward_right()
{
    Serial.println("mw_backward_right");
    // motor_stop(1);
    // motor_backward(2);
    // motor_backward(3);
    // motor_stop(4);
}
void mw_clockwise()
{
    Serial.println("mw_clockwise");
    motor_forward(1);
    motor_backward(2);
    motor_forward(3);
    motor_backward(4);
}
void mw_counterclockwise()
{
    Serial.println("mw_counterclockwise");
    motor_backward(1);
    motor_forward(2);
    motor_backward(3);
    motor_forward(4);
}
void mw_stop()
{
    Serial.println("mw_stop");
    motor_stop(1);
    motor_stop(2);
    motor_stop(3);
    motor_stop(4);
}

void notify()
{
    //--- Digital cross/square/triangle/circle button events ---
    ////////////////////
    if (Ps3.event.button_down.triangle)
    {
        Serial.println("Started pressing the triangle button");
        motor_forward(1);
    }

    if (Ps3.event.button_up.triangle)
    {
        Serial.println("Released the triangle button");
        motor_stop(1);
    }
    //////////////////////////
    if (Ps3.event.button_down.cross)
    {
        Serial.println("Started pressing the cross button");
        motor_forward(2);
    }

    if (Ps3.event.button_up.cross)
    {
        Serial.println("Released the cross button");
        motor_stop(2);
    }
    ////////////////////

    if (Ps3.event.button_down.square)
    {
        Serial.println("Started pressing the square button");
        motor_forward(3);
    }

    if (Ps3.event.button_up.square)
    {
        Serial.println("Released the square button");
        motor_stop(3);
    }

    ////////////////////
    if (Ps3.event.button_down.circle)
    {
        Serial.println("Started pressing the circle button");
        motor_forward(4);
    }
        
    if (Ps3.event.button_up.circle)
    {
        Serial.println("Released the circle button");
        motor_stop(4);
    }
        

    //--------------- Digital D-pad button events --------------
    if (Ps3.event.button_down.up)
    {
        Serial.println("Started pressing the up button");
    }
    if (Ps3.event.button_up.up)
    {
        Serial.println("Released the up button");
    }

    if (Ps3.event.button_down.down)
    {
        Serial.println("Started pressing the down button");
    }
    if (Ps3.event.button_up.down)
    {
        Serial.println("Released the down button");
    }
    if (Ps3.event.button_down.right)
    {
        Serial.println("Started pressing the right button");
        mw_clockwise();
    }
        
    if (Ps3.event.button_up.right)
    {
        Serial.println("Released the right button");
        mw_stop();
    }
        
    if (Ps3.event.button_down.left)
    {
        Serial.println("Started pressing the left button");
        mw_counterclockwise();
    }
        
    if (Ps3.event.button_up.left)
    {
        Serial.println("Released the left button");
        mw_stop();
    }
        

    //------------- Digital shoulder button events -------------
    if (Ps3.event.button_down.l1)
        Serial.println("Started pressing the left shoulder button");
    if (Ps3.event.button_up.l1)
        Serial.println("Released the left shoulder button");

    if (Ps3.event.button_down.r1)
        Serial.println("Started pressing the right shoulder button");
    if (Ps3.event.button_up.r1)
        Serial.println("Released the right shoulder button");

    //-------------- Digital trigger button events -------------
    if (Ps3.event.button_down.l2)
        Serial.println("Started pressing the left trigger button");
    if (Ps3.event.button_up.l2)
        Serial.println("Released the left trigger button");

    if (Ps3.event.button_down.r2)
        Serial.println("Started pressing the right trigger button");
    if (Ps3.event.button_up.r2)
        Serial.println("Released the right trigger button");

    //--------------- Digital stick button events --------------
    if (Ps3.event.button_down.l3)
        Serial.println("Started pressing the left stick button");
    if (Ps3.event.button_up.l3)
        Serial.println("Released the left stick button");

    if (Ps3.event.button_down.r3)
        Serial.println("Started pressing the right stick button");
    if (Ps3.event.button_up.r3)
        Serial.println("Released the right stick button");

    //---------- Digital select/start/ps button events ---------
    if (Ps3.event.button_down.select)
        Serial.println("Started pressing the select button");
    if (Ps3.event.button_up.select)
        Serial.println("Released the select button");

    if (Ps3.event.button_down.start)
        Serial.println("Started pressing the start button");
    if (Ps3.event.button_up.start)
        Serial.println("Released the start button");

    if (Ps3.event.button_down.ps)
        Serial.println("Started pressing the Playstation button");
    if (Ps3.event.button_up.ps)
        Serial.println("Released the Playstation button");

    //---------------- Analog stick value events ---------------
    if (abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2)
    {
        Serial.print("Moved the left stick:");
        Serial.print(" x=");
        Serial.print(Ps3.data.analog.stick.lx, DEC);
        Serial.print(" y=");
        Serial.print(Ps3.data.analog.stick.ly, DEC);
        Serial.println();

        if ((abs(Ps3.data.analog.stick.lx) < THRESHOLD_ABS) && (abs(Ps3.data.analog.stick.ly) < THRESHOLD_ABS))
            mw_stop();
        if ((abs(Ps3.data.analog.stick.lx) < THRESHOLD_ABS) && (Ps3.data.analog.stick.ly < THRESHOLD_NEG))
            mw_forward();
        if ((abs(Ps3.data.analog.stick.lx) < THRESHOLD_ABS) && (Ps3.data.analog.stick.ly > THRESHOLD_POS))
            mw_backward();
        if ((Ps3.data.analog.stick.lx < THRESHOLD_NEG) && (abs(Ps3.data.analog.stick.ly) < THRESHOLD_ABS))
            mw_left();
        if ((Ps3.data.analog.stick.lx > THRESHOLD_POS) && (abs(Ps3.data.analog.stick.ly) < THRESHOLD_ABS))
            mw_right();
        if ((Ps3.data.analog.stick.lx < THRESHOLD_NEG) && (Ps3.data.analog.stick.ly < THRESHOLD_NEG))
            mw_forward_left();
        if ((Ps3.data.analog.stick.lx > THRESHOLD_POS) && (Ps3.data.analog.stick.ly < THRESHOLD_NEG))
            mw_forward_right();
        if ((Ps3.data.analog.stick.lx < THRESHOLD_NEG) && (Ps3.data.analog.stick.ly > THRESHOLD_POS))
            mw_backward_left();
        if ((Ps3.data.analog.stick.lx > THRESHOLD_POS) && (Ps3.data.analog.stick.ly > THRESHOLD_POS))
            mw_backward_right();
    }

    if (abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2)
    {
        Serial.print("Moved the right stick:");
        Serial.print(" x=");
        Serial.print(Ps3.data.analog.stick.rx, DEC);
        Serial.print(" y=");
        Serial.print(Ps3.data.analog.stick.ry, DEC);
        Serial.println();

        // if ((Ps3.data.analog.stick.rx < THRESHOLD_NEG) && (abs(Ps3.data.analog.stick.ry) < THRESHOLD_ABS))
        //     mw_counterclockwise();
        // if ((Ps3.data.analog.stick.rx > THRESHOLD_POS) && (abs(Ps3.data.analog.stick.ry) < THRESHOLD_ABS))
        //     mw_clockwise();
    }

    //--------------- Analog D-pad button events ----------------
    if (abs(Ps3.event.analog_changed.button.up))
    {
        Serial.print("Pressing the up button: ");
        Serial.println(Ps3.data.analog.button.up, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.right))
    {
        Serial.print("Pressing the right button: ");
        Serial.println(Ps3.data.analog.button.right, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.down))
    {
        Serial.print("Pressing the down button: ");
        Serial.println(Ps3.data.analog.button.down, DEC);
    }
    if (abs(Ps3.event.analog_changed.button.left))
    {
        Serial.print("Pressing the left button: ");
        Serial.println(Ps3.data.analog.button.left, DEC);
    }

    //---------- Analog shoulder/trigger button events ----------
    if (abs(Ps3.event.analog_changed.button.l1))
    {
        Serial.print("Pressing the left shoulder button: ");
        Serial.println(Ps3.data.analog.button.l1, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.r1))
    {
        Serial.print("Pressing the right shoulder button: ");
        Serial.println(Ps3.data.analog.button.r1, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.l2))
    {
        Serial.print("Pressing the left trigger button: ");
        Serial.println(Ps3.data.analog.button.l2, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.r2))
    {
        Serial.print("Pressing the right trigger button: ");
        Serial.println(Ps3.data.analog.button.r2, DEC);
    }

    //---- Analog cross/square/triangle/circle button events ----
    if (abs(Ps3.event.analog_changed.button.triangle))
    {
        Serial.print("Pressing the triangle button: ");
        Serial.println(Ps3.data.analog.button.triangle, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.circle))
    {
        Serial.print("Pressing the circle button: ");
        Serial.println(Ps3.data.analog.button.circle, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.cross))
    {
        Serial.print("Pressing the cross button: ");
        Serial.println(Ps3.data.analog.button.cross, DEC);
    }

    if (abs(Ps3.event.analog_changed.button.square))
    {
        Serial.print("Pressing the square button: ");
        Serial.println(Ps3.data.analog.button.square, DEC);
    }

    //---------------------- Battery events ---------------------
    // if (battery != Ps3.data.status.battery)
    // {
    //     battery = Ps3.data.status.battery;
    //     Serial.print("The controller battery is ");
    //     // if (battery == ps3_status_battery_charging)
    //     //     Serial.println("charging");
    //     // else if (battery == ps3_status_battery_full)
    //     //     Serial.println("FULL");
    //     // else if (battery == ps3_status_battery_high)
    //     //     Serial.println("HIGH");
    //     // else
    //     if (battery == ps3_status_battery_low)
    //         Serial.println("LOW");
    //     // else if (battery == ps3_status_battery_dying)
    //     //     Serial.println("DYING");
    //     // else if (battery == ps3_status_battery_shutdown)
    //     //     Serial.println("SHUTDOWN");
    //     // else
    //     //     Serial.println("UNDEFINED");
    // }
}

void onConnect()
{
    Serial.println("Connected.");
}

void setup()
{
    Serial.begin(115200);
    Ps3.attach(notify);
    Ps3.attachOnConnect(onConnect);
    Ps3.begin();

    Serial.println("Ready.");
    pinMode(27, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(17, OUTPUT);
}

void loop()
{
}
