package han.Cleanify


import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.support.v7.widget.Toolbar
import android.view.Menu
import com.androidquery.AQuery
import android.view.MenuItem
import android.widget.Toast
import android.view.View
import com.github.kittinunf.fuel.Fuel
import han.Cleanify.MainActivity.*
import com.androidquery.util.AQUtility.postDelayed
import android.view.MotionEvent
import android.widget.SeekBar;




internal var aq: AQuery? = null
const val url = "http://192.168.43.78:8000/control"

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val toolbar = findViewById(R.id.toolbar) as Toolbar
        setSupportActionBar(toolbar)
        val speed = findViewById(R.id.wheels) as SeekBar
        val brush = findViewById(R.id.brushes) as SeekBar
        val forw = findViewById(R.id.forward)
        forw.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "forward" + "\", \"session\" : \"webapp\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\"}").response { request, response, result ->
                }

            }
            false
        })

        val fl = findViewById(R.id.forward_left)
        fl.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "forward-left" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val fr = findViewById(R.id.forward_right)
        fr.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "forward-right" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val l = findViewById(R.id.left)
        l.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "left" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val r = findViewById(R.id.right)
        r.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "right" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val bl = findViewById(R.id.backward_left)
        bl.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "backward-left" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val b = findViewById(R.id.backward)
        b.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "backward" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
                println(brush.progress)
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val br = findViewById(R.id.backward_right)
        br.setOnTouchListener(View.OnTouchListener { v, event ->
            if (event.action == MotionEvent.ACTION_DOWN) {
                Fuel.post(url).body("{\"direction\" : \"" + "backward-right" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }
            }
            if (event.action == MotionEvent.ACTION_UP) {
                Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
                }

            }
            false
        })

        val stop = findViewById(R.id.stop)
        stop.setOnClickListener {
            Fuel.post(url).body("{\"direction\" : \"" + "stop" + "\", \"session\" : \"webapp\", \"brush_speed\" : \"" + brush.progress + "\"}").response { request, response, result ->
            }
        }
    }



    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        val id = item.itemId


        if (id == R.id.action_settings) {
            return true
        }

        return super.onOptionsItemSelected(item)
    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
