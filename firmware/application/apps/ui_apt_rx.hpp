#include "ui.hpp"
#include "ui_widget.hpp"
#include "ui_navigation.hpp"
#include "string_format.hpp"
#include "ui_receiver.hpp"

// Define a constant
#define PROGRESS_MAX 100

namespace ui
{
    class APTRXView : public View                           // App class declaration
    {
    public:

        // Public declarations
    	void focus() override;                              // ui::View function override

        APTRXView(NavigationView &nav);                     // App class init function declaration
        std::string title() const override {
            return "APT RX";                                // App Title
        };

    private:

        // Private declarations
        void update();                                      // Function declaration
        MessageHandlerRegistration message_handler_update{  // Example, not required: MessageHandlerRegistration class
            Message::ID::DisplayFrameSync,                  // relays machine states to your app code. Every time you
            [this](const Message *const) {                  // get a  DisplayFrameSync message the update() function will
                this->update();                             // be triggered.
            }
        };

        // Variables
        int32_t asdf = 0;
        int32_t i=0;
        int32_t j=0;

        // Widgets
        // Note: Usable screen space is 240x304px
        // Note: Each char takes up 8x8px so you can multiply
        //       the amount of spaces and rows you want by 8.
        //       This gives you 30x38 char

        Labels labels_gain {
            { { 0 * 8, 2 * 8 }, "LNA:   VGA:   AMP:", Color::light_grey() }
        };

        LNAGainField field_lna {
            { 4 * 8, 1 * 16 }
        };

        VGAGainField field_vga {
            { 11 * 8, 1 * 16 }
        };

        RFAmpField field_rf_amp {
            { 18 * 8, 1 * 16 }
        };

        // maybe activate this one later.
//        RSSI rssi {
//            { 20 * 8, 2 * 4, 10 * 8, 8 },
//        };

        Labels labels_freq {
            { { 0 * 8, 0 * 8 }, "Freq           NOAA:", Color::light_grey() }
        };

        OptionsField options_freq {
            { 22 * 8, 0 * 16 },
            3,
            {
                { " 15", 137.62 },
                { " 18", 2 },
                { " 19", 3 }
            }
        };

        FrequencyField field_freq {
            { 5 * 8, 0 * 16 },
        };


    };  // class APTRXView
}       // namespace ui
