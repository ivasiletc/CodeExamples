package edu.pjatk.unikino

import org.hibernate.annotations.LazyCollection
import org.hibernate.annotations.LazyCollectionOption
import javax.persistence.CascadeType
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id
import javax.persistence.OneToMany

@Entity
class Klient(val telefon: String,
             override val imie: String,
             override val nazwisko: String) : Osoba()
{
    @OneToMany(mappedBy = "klient", cascade = [CascadeType.MERGE])
    @LazyCollection(LazyCollectionOption.FALSE)
    lateinit var rezerwacji: MutableSet<Rezerwacja>

    @Id
    @GeneratedValue
    private val id: Long? = null

}