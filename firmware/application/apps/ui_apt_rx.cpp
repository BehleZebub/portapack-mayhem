#include "ui_apt_rx.hpp"
#include "portapack.hpp"
#include <cstring>

using namespace portapack;

namespace ui
{

    void APTRXView::focus()
    {                                // Default selection to button_helloWorld when app starts
	    options_freq.focus();
    }

    APTRXView::APTRXView(NavigationView &nav)                // Application Main
    {
        add_children({                                       // Add pointers for widgets
            &labels_gain,
            &field_lna,
            &field_vga,
            &field_rf_amp,
//            &rssi,
            &labels_freq,
            &options_freq,
            &field_freq
        });

        options_freq.on_change = [this](size_t n, OptionsField::value_t v)
        {
            switch(n)
            {
                case 0: asdf=137620000; break;  // NOAA 15
                case 1: asdf=137912500; break;  // NOAA 18
                case 2: asdf=137100000; break;  // NOAA 19
            }
            field_freq.set_value(asdf);
        };
    }

    void APTRXView::update()                                 // Every time you get a DisplayFrameSync message this
    {                                                        // function will be ran.
    // Message code
    // this will create a nice pattern on screen to test dynamic image creation.
    // I tried to work with bitmap widgets but they are too static for dynamic pixel data.

        std::array<ui::Color, 220> px_color;                // create line buffer with 220px.
    // clear screen
        //display.fill_rectangle(Rect(10, 60, 220, 220), Color::white());

    // this loops through all avaiable pixels and calculates the image.
        for(i=0;i<220;i++)
        {
            for(j=0;j<220;j++)
            {
                px_color[j]=(i*j)%16;
            }
            display.draw_pixels({10,i+60,220,1},px_color);
        }
    }
}
