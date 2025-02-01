

async function midi_testing()
{
    try
    {
        const access = await navigator.requestMIDIAccess();
        console.log(access);

        access.outputs.forEach(device => {
            console.log(device);
            console.log(
                `Output port [type:'${device.type}']
                    id:'${device.id}'
                    manufacturer:'${device.manufacturer}'
                    name:'${device.name}'
                    version:'${device.version}'
                `);
            // volca 48-57
            testSendNote(access, device.id, 57, 2)
            // 60 middle C
            testSendNote(access, device.id, 60, 0)
        });
    }
    catch (error)
    {
        if (error.name === "SecurityError")
        {
            console.error("The website is not allowed to control and reprogram MIDI devices.");
        }
        console.error(error);
    }
}


function testSendNote(midiAccess, portID, note, channel)
{
    // note on middle C, full velocity
    // 0x90 means Note on (0x->9<-0) on Chan 1 (0x9->0<-)
    // velocity
    const noteOnMessage = [(0x90 + channel), note, 0x7f];
    const output = midiAccess.outputs.get(portID);
    // omitting the timestamp means send immediately.
    output.send(noteOnMessage);
    // timestamp = now + 1000ms.
    output.send([(0x80+channel), note, 0x40], window.performance.now() + 1000.0);
}


// function onMIDIMessage(event) {
//     let str = `MIDI message received at timestamp ${event.timeStamp}[${event.data.length} bytes]: `;
//     for (const character of event.data) {
//       str += `0x${character.toString(16)} `;
//     }
//     console.log(str);
//   }

//   function startLoggingMIDIInput(midiAccess) {
//     midiAccess.inputs.forEach((entry) => {
//       entry.onmidimessage = onMIDIMessage;
//     });
//   }


midi_testing();
