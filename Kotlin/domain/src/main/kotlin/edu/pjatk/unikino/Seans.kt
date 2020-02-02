package edu.pjatk.unikino

import org.hibernate.annotations.LazyCollection
import org.hibernate.annotations.LazyCollectionOption
import org.springframework.beans.factory.annotation.Autowired
import java.time.LocalDate
import java.time.LocalTime
import javax.persistence.CascadeType
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id
import javax.persistence.ManyToMany
import javax.persistence.ManyToOne

@Entity
data class Seans(val data: LocalDate,
                 val godzinaOd: LocalTime,
                 val godzinaDo: LocalTime,
                 @ManyToOne(cascade = [CascadeType.REFRESH, CascadeType.DETACH, CascadeType.MERGE])
                 var film: Film,
                 @ManyToOne(cascade = [CascadeType.REFRESH, CascadeType.DETACH, CascadeType.MERGE])
                 val sala: Sala)
{

    val czas: String = godzinaOd.toString() + "-" + godzinaDo.toString()
    
    @ManyToMany(mappedBy = "seans", cascade = [CascadeType.MERGE])
    @LazyCollection(LazyCollectionOption.FALSE)
    var rezerwacji: MutableSet<Rezerwacja> = mutableSetOf()

    @Id
    @GeneratedValue
    private val id: Long? = null

    override fun toString(): String
    {
        return film.opis
    }
    
}