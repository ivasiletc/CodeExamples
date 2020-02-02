package edu.pjatk.unikino

import org.hibernate.annotations.LazyCollection
import org.hibernate.annotations.LazyCollectionOption
import javax.persistence.CascadeType
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id
import javax.persistence.OneToMany

@Entity
class Kinoteatr(val godzinyPracy: String,
                val telefonKontaktowy: String,
                val ulica: String)
{
    @OneToMany(mappedBy = "kinoteatr", orphanRemoval = true, cascade = [CascadeType.ALL])
    @LazyCollection(LazyCollectionOption.FALSE)
    lateinit var sali: MutableSet<Sala>
    
    
    @Id
    @GeneratedValue
    private val id: Long? = null
}