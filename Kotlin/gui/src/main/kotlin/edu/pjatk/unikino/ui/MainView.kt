package edu.pjatk.unikino.ui

import com.vaadin.server.Page
import com.vaadin.server.VaadinRequest
import com.vaadin.spring.annotation.SpringUI
import com.vaadin.ui.ComboBox
import com.vaadin.ui.Grid
import com.vaadin.ui.Label
import com.vaadin.ui.Layout
import com.vaadin.ui.Notification
import com.vaadin.ui.UI
import com.vaadin.ui.VerticalLayout
import edu.pjatk.unikino.Film
import edu.pjatk.unikino.Seans
import edu.pjatk.unikino.boot.FilmRepository
import edu.pjatk.unikino.boot.SeansRepository
import org.springframework.beans.factory.annotation.Autowired

@SpringUI
class MainView : UI() {

    @Autowired
    lateinit var filmRepository: FilmRepository
    @Autowired
    lateinit var seansRepository: SeansRepository
    
    val grid = Grid(Seans::class.java)
    
    val additionalStyle: String = """
        #ROOT-2521314{
            background-color: black;
            background-image: url("https://pp.userapi.com/c637420/v637420019/51e37/dKiDzm6Ssow.jpg");
            background-size: cover;
        }
        .v-label{
            font-size: 52pt;
            color: white;
        }
    """.trimIndent()
    
    override fun init(request: VaadinRequest?) {
        content = createMainLayout()

        val styles = Page.getCurrent().getStyles()
        styles.add(additionalStyle)
        
        createComboBoxWithFilm()
    }

    fun createMainLayout(): Layout {
        val comboBox = createComboBoxWithFilm()
        val gridWithSeans = createGridWithSeans()

        val label = Label("UniKino")
        
        val verticalLayout = VerticalLayout(label, comboBox, gridWithSeans)
        
        return verticalLayout
    }

    fun createComboBoxWithFilm(): ComboBox<Film>
    {
        val filmy: MutableList<Film> = filmRepository.findAll() as MutableList<Film>
        val comboBox = ComboBox<Film>()

        comboBox.placeholder = "Film..."
        comboBox.setItemCaptionGenerator(Film::nazwa)
        comboBox.isEmptySelectionAllowed = false
        comboBox.setItems(filmy)

        comboBox.addValueChangeListener({ update(it.value) })

        return comboBox
    }

    fun createGridWithSeans(): Grid<Seans>
    {
        grid.setSizeFull()
        grid.setSelectionMode(Grid.SelectionMode.SINGLE)
        grid.setItems(seansRepository.findAll() as MutableList<Seans>)
        grid.setColumns("data", "film", "czas", "sala")
        grid.sort("czas")
        
        grid.addItemClickListener {
            event -> Notification.show("Opis:\n " + event.item,
            Notification.Type.HUMANIZED_MESSAGE)
            
        }

        return grid
    }

    fun update(film: Film?) {
        grid.setItems(film!!.seansy)
    }
    
}
